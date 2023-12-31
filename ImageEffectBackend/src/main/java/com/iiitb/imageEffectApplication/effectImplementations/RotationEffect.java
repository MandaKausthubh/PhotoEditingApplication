package com.iiitb.imageEffectApplication.effectImplementations;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueDiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.RotationInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class RotationEffect implements SingleValueDiscreteEffect {
    private int value;
    public void setParameterValue(int parameterValue) throws IllegalParameterException{
        if(parameterValue<0 || parameterValue>4) throw new IllegalParameterException("Inavlid params, expected 0 ,1 ,3 , 4");
        this.value=parameterValue;
    }
    
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Rotation", Integer.toString(value*90));
        return RotationInterface.applyRotation(image, value);
    }

    
}
