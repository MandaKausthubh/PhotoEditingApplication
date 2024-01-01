package com.iiitb.imageEffectApplication.effectImplementations;



import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.BrightnessInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.GaussianBlurInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;



public class GaussianBlurEffect implements SingleValueParameterizableEffect{
    private float radius;
    public void setParameterValue(float parameterValue) throws IllegalParameterException{
        // parameter should be between 0 and 1
        if(parameterValue>1 || parameterValue<0) throw new IllegalParameterException("Inavalid params, expected a real number in [0, 1]");
        this.radius=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
       
        loggingService.addLog(fileName, "Gaussian Blur", Float.toString(radius)); // handling logging for this 

        return GaussianBlurInterface.applyGaussianBlur(image, radius);

    }
    
}
