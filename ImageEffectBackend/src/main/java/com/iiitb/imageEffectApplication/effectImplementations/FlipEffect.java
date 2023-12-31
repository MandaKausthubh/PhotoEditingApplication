package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.libraryInterfaces.FlipInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;

public class FlipEffect implements DiscreteEffect{
    private int hFlip, vFlip;
    public void selectOptionValue(String optionName, int value) throws IllegalParameterException{
        if(optionName!="h" && optionName!="v") throw new IllegalParameterException("Invalid params, expected 'h' or 'v'");
        if(optionName.equals("h")) this.hFlip=value;
        else if(optionName.equals("v")) this.vFlip=value;

    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
    
        loggingService.addLog(fileName, "Flip", hFlip+","+vFlip);
        return FlipInterface.applyFlip(image, hFlip, vFlip);
    }
    
}
