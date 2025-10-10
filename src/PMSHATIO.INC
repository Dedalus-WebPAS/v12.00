.
. PMSHATIO    
. --------
. Filename     : pmshataf.dat
.
RSPMHAT1  RESET     KEY39                                                       
          READ      PMSHATA1,KEY39;;                                            
          RETURN
.
RAPMHAT1  RESET     KEY39                                                       
          MOVE      ZERO,OVRCD
          READ      PMSHATA1,KEY39;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMHAT1  RESET     KEY39                                                       
          MOVE      ZERO,OVRCD
          READ      PMSHATA1,KEY39;PMHTHOSP,PMHTTYPE,PMHTKVAL,PMHTSDAT,PMHTEDAT:
                                   PMHTTXT1,PMHTTXT2,PMHTTXT3,PMHTTXT4,PMHTVAL1:
                                   PMHTVAL2,PMHTVAL3,PMHTVAL4,PMHTIND1,PMHTIND2:
                                   PMHTIND3,PMHTIND4,PMHTCOD1,PMHTCOD2,PMHTCOD3:
                                   PMHTCOD4,PMHTCUSR,PMHTCDAT,PMHTCTIM,PMHTUUSR:
                                   PMHTUDAT,PMHTUTIM,PMHTFUSR,PMHTFDAT,PMHTFTIM:
                                   PMHTSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMHAT1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSHATA1;PMHTHOSP,PMHTTYPE,PMHTKVAL,PMHTSDAT,PMHTEDAT:      
                             PMHTTXT1,PMHTTXT2,PMHTTXT3,PMHTTXT4,PMHTVAL1:      
                             PMHTVAL2,PMHTVAL3,PMHTVAL4,PMHTIND1,PMHTIND2:      
                             PMHTIND3,PMHTIND4,PMHTCOD1,PMHTCOD2,PMHTCOD3:      
                             PMHTCOD4,PMHTCUSR,PMHTCDAT,PMHTCTIM,PMHTUUSR:      
                             PMHTUDAT,PMHTUTIM,PMHTFUSR,PMHTFDAT,PMHTFTIM:      
                             PMHTSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMHAT1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSHATA1;PMHTHOSP,PMHTTYPE,PMHTKVAL,PMHTSDAT,PMHTEDAT:      
                             PMHTTXT1,PMHTTXT2,PMHTTXT3,PMHTTXT4,PMHTVAL1:      
                             PMHTVAL2,PMHTVAL3,PMHTVAL4,PMHTIND1,PMHTIND2:      
                             PMHTIND3,PMHTIND4,PMHTCOD1,PMHTCOD2,PMHTCOD3:      
                             PMHTCOD4,PMHTCUSR,PMHTCDAT,PMHTCTIM,PMHTUUSR:      
                             PMHTUDAT,PMHTUTIM,PMHTFUSR,PMHTFDAT,PMHTFTIM:      
                             PMHTSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMHAT1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSHATA1;PMHTHOSP,PMHTTYPE,PMHTKVAL,PMHTSDAT,PMHTEDAT:      
                             PMHTTXT1,PMHTTXT2,PMHTTXT3,PMHTTXT4,PMHTVAL1:      
                             PMHTVAL2,PMHTVAL3,PMHTVAL4,PMHTIND1,PMHTIND2:      
                             PMHTIND3,PMHTIND4,PMHTCOD1,PMHTCOD2,PMHTCOD3:      
                             PMHTCOD4,PMHTCUSR,PMHTCDAT,PMHTCTIM,PMHTUUSR:      
                             PMHTUDAT,PMHTUTIM,PMHTFUSR,PMHTFDAT,PMHTFTIM:      
                             PMHTSPAR                                           
          RETURN
.
WRPMHAT1  RESET     KEY39                                                       
          WRITE     PMSHATA1,KEY39;PMHTHOSP,PMHTTYPE,PMHTKVAL,PMHTSDAT,PMHTEDAT:
                                   PMHTTXT1,PMHTTXT2,PMHTTXT3,PMHTTXT4,PMHTVAL1:
                                   PMHTVAL2,PMHTVAL3,PMHTVAL4,PMHTIND1,PMHTIND2:
                                   PMHTIND3,PMHTIND4,PMHTCOD1,PMHTCOD2,PMHTCOD3:
                                   PMHTCOD4,PMHTCUSR,PMHTCDAT,PMHTCTIM,PMHTUUSR:
                                   PMHTUDAT,PMHTUTIM,PMHTFUSR,PMHTFDAT,PMHTFTIM:
                                   PMHTSPAR                                     
          RETURN
.
DEPMHAT1  RESET     KEY39                                                       
          DELETE    PMSHATA1,KEY39                                              
          RETURN
.
