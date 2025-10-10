.
. WEBDVBIO    
. --------
. Filename     : webdvbaf.dat
.
RSWBDVB1  RESET     KEY8                                                        
          READ      WEBDVBA1,KEY8;;                                             
          RETURN
.
RAWBDVB1  RESET     KEY8                                                        
          MOVE      ZERO,OVRCD
          READ      WEBDVBA1,KEY8;ANS                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVB1  RESET     KEY8                                                        
          MOVE      ZERO,OVRCD
          READ      WEBDVBA1,KEY8;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC: 
                                  WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR  
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVB1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVBA1;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVB1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVBA1;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVB1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVBA1;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          RETURN
.
WRWBDVB1  RESET     KEY8                                                        
          WRITE     WEBDVBA1,KEY8;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC: 
                                  WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR  
          RETURN
.
DEWBDVB1  RESET     KEY8                                                        
          DELETE    WEBDVBA1,KEY8                                               
          RETURN
.
RSWBDVB2  RESET     KEY16                                                       
          READ      WEBDVBA2,KEY16;;                                            
          RETURN
.
RAWBDVB2  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVBA2,KEY16;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVB2  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVBA2,KEY16;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:
                                   WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVB2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVBA2;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVB2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVBA2;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVB2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVBA2;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:      
                             WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR       
          RETURN
.
WRWBDVB2  RESET     KEY16                                                       
          WRITE     WEBDVBA2,KEY16;WBDBBTHN,WBDBBTHL,WBDBTRIB,WBDBDTBC,WBDBTMBC:
                                   WBDBOPER,WBDBEFNM,WBDBLOCN,WBDBSNID,WBDBSPAR 
          RETURN
.
DEWBDVB2  RESET     KEY16                                                       
          DELETE    WEBDVBA2,KEY16                                              
          RETURN
.
