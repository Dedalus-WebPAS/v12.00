.
. WEBDVEIO    
. --------
. Filename     : webdveaf.dat
.
RSWBDVE1  RESET     KEY35                                                       
          READ      WEBDVEA1,KEY35;;                                            
          RETURN
.
RAWBDVE1  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA1,KEY35;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVE1  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA1,KEY35;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVE1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVEA1;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVE1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVEA1;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVE1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVEA1;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          RETURN
.
WRWBDVE1  RESET     KEY35                                                       
          WRITE     WEBDVEA1,KEY35;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          RETURN
.
DEWBDVE1  RESET     KEY35                                                       
          DELETE    WEBDVEA1,KEY35                                              
          RETURN
.
RSWBDVE2  RESET     KEY59                                                       
          READ      WEBDVEA2,KEY59;;                                            
          RETURN
.
RAWBDVE2  RESET     KEY59                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA2,KEY59;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVE2  RESET     KEY59                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA2,KEY59;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVE2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVEA2;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVE2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVEA2;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVE2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVEA2;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          RETURN
.
WRWBDVE2  RESET     KEY59                                                       
          WRITE     WEBDVEA2,KEY59;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          RETURN
.
DEWBDVE2  RESET     KEY59                                                       
          DELETE    WEBDVEA2,KEY59                                              
          RETURN
.
RSWBDVE3  RESET     KEY71                                                       
          READ      WEBDVEA3,KEY71;;                                            
          RETURN
.
RAWBDVE3  RESET     KEY71                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA3,KEY71;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVE3  RESET     KEY71                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA3,KEY71;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVE3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVEA3;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVE3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVEA3;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVE3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVEA3;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          RETURN
.
WRWBDVE3  RESET     KEY71                                                       
          WRITE     WEBDVEA3,KEY71;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          RETURN
.
DEWBDVE3  RESET     KEY71                                                       
          DELETE    WEBDVEA3,KEY71                                              
          RETURN
.
RSWBDVE4  RESET     KEY35                                                       
          READ      WEBDVEA4,KEY35;;                                            
          RETURN
.
RAWBDVE4  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA4,KEY35;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVE4  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVEA4,KEY35;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVE4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVEA4;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVE4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVEA4;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVE4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVEA4;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:      
                             WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:      
                             WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR       
          RETURN
.
WRWBDVE4  RESET     KEY35                                                       
          WRITE     WEBDVEA4,KEY35;WBDECLID,WBDERPTC,WBDEMEVC,WBDEEVDT,WBDEEVID:
                                   WBDEPTSC,WBDEPTST,WBDEPTMN,WBDEPTMR,WBDEPTFN:
                                   WBDEPTGN,WBDETRID,WBDEMSID,WBDERKEY,WBDESPAR 
          RETURN
.
DEWBDVE4  RESET     KEY35                                                       
          DELETE    WEBDVEA4,KEY35                                              
          RETURN
.
