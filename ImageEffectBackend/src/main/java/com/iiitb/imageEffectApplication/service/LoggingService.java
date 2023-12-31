package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;


import java.io.FileWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class LoggingService {
    String DB_FILE="logDB.txt"; // File that serves as database for logs
    List<LogModel> listOfLogs=null;
    FileWriter fw;

    LoggingService(){
     listOfLogs=new ArrayList<LogModel>(); // complete list of all logs
     fw=null;
    }

    public void addLog(String fileName, String effectName, String optionValues) {

        LocalDateTime currentDateTime = LocalDateTime.now(); // Define the desired date-time format
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy-HH:mm"); // Format the timestamp as a string
        String formattedTimestamp = currentDateTime.format(formatter);

        LogModel lm=new LogModel(formattedTimestamp, fileName, effectName, optionValues); // crearing log module

        listOfLogs.add(lm); // active logs
        
        try{ fw=new FileWriter(DB_FILE, true); } // Open the file in append mode
        catch(IOException e){ e.printStackTrace();}
        
        try { fw.write(formattedTimestamp+" "+effectName+" "+optionValues+" "+ fileName+"\n"); /*System.out.println("WRITTEN");*/ }
        catch(IOException e){ e.printStackTrace(); }

        try{ fw.close();} // close fw
        catch(IOException e){ e.printStackTrace(); }

        return;
    }

    public List<LogModel> getAllLogs() {
        
        List<LogModel> newList=new ArrayList<LogModel>();

        try (Scanner scanner = new Scanner(new File(DB_FILE))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                
                // Split the line using space as a delimiter " "
                String[] parts = line.split(" ");
                //System.out.println("PARTS: "+parts.length);
                String timestamp = parts[0];
                String effectName = parts[1];
                String optionValues = parts[2];
                String fileName="";
                for(int i=3; i<parts.length; i++) fileName+=parts[i];

                LogModel lm=new LogModel(timestamp, fileName, effectName, optionValues);
                newList.add(lm);

            }
        }
        catch(FileNotFoundException e){ 
            System.err.println("DB Failure.");
            e.printStackTrace();
        }

        listOfLogs=newList;
        return listOfLogs;

    }

    public List<LogModel> getLogsByEffect(String effectName) {
        List<LogModel> newList=new ArrayList<LogModel>();
        for(LogModel entry: listOfLogs){
            if(entry.getEffectName().equals(effectName)) newList.add(entry);
        }
        return newList;
    }

    public void clearLogs() { // Flush DB
        try{ fw=new FileWriter(DB_FILE); } // Open the file in overwrite mode
        catch(IOException e){ e.printStackTrace();}
        
        try { fw.write(""); /*System.out.println("WRITTEN");*/ }
        catch(IOException e){ e.printStackTrace(); }
    
        try{ fw.close();} // close fw
        catch(IOException e){ e.printStackTrace(); }

        listOfLogs.clear();
        return;
    }

    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {
        List<LogModel> newList=new ArrayList<LogModel>();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy-HH:mm"); // To format the LocalDateTime object
        

        for(LogModel lm: listOfLogs){
            String st = startTime.format(formatter); // Extract timestamp in form of a String
            String en= endTime.format(formatter); 
            try{
                if(isTimestampBetween(lm.getTimestamp(), st, en)) newList.add(lm);
            }catch(ParseException e){
                e.printStackTrace();
            }
        }
        
        return newList;
    }

    public boolean isTimestampBetween(String timestampToCheck, String startTime, String endTime) // to check if a given timestamp lies between 2 other timestamps
            throws ParseException {
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy-HH:mm");

        Date timestampDate = dateFormat.parse(timestampToCheck);
        Date startDate = dateFormat.parse(startTime);
        Date endDate = dateFormat.parse(endTime);

        return timestampDate.after(startDate) && timestampDate.before(endDate);
    }
}
