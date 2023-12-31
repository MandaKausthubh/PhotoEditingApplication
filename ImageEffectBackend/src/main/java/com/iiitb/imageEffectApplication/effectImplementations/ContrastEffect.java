package com.iiitb.imageEffectApplication.effectImplementations;

import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class ContrastEffect {
    private float amount;
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>2) throw new IllegalParameterException("Invalid params, expected real no in [0, 2].");
        this.amount=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Contrast", Float.toString(amount));
        return ContrastInterface.applyContrast(image, amount);
    }
    
    
}
