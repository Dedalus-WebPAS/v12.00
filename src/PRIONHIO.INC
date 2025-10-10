.
. PRIONHIO    
. --------
. Filename     : prionhaf.dat
.
RSPRONH1  RESET     KEY24                                                       
          READ      PRIONHA1,KEY24;;                                            
          RETURN
.
RAPRONH1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PRIONHA1,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRONH1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PRIONHA1,KEY24;PRONUNIQ,PRONTDAT,PRONTTIM,PRONUSID,PRONHRSN:
                                   PRONFTXT,PRONACTN,PRONDOCT,PRONPRAC,PRONPIND:
                                   PRONCLAM,PRONHFND,PRONHIFD,PRONSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRONH1  MOVE      ZERO,OVRCD                                                  
          READKS    PRIONHA1;PRONUNIQ,PRONTDAT,PRONTTIM,PRONUSID,PRONHRSN:      
                             PRONFTXT,PRONACTN,PRONDOCT,PRONPRAC,PRONPIND:      
                             PRONCLAM,PRONHFND,PRONHIFD,PRONSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRONH1  MOVE      ZERO,OVRCD                                                  
          READKP    PRIONHA1;PRONUNIQ,PRONTDAT,PRONTTIM,PRONUSID,PRONHRSN:      
                             PRONFTXT,PRONACTN,PRONDOCT,PRONPRAC,PRONPIND:      
                             PRONCLAM,PRONHFND,PRONHIFD,PRONSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRONH1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIONHA1;PRONUNIQ,PRONTDAT,PRONTTIM,PRONUSID,PRONHRSN:      
                             PRONFTXT,PRONACTN,PRONDOCT,PRONPRAC,PRONPIND:      
                             PRONCLAM,PRONHFND,PRONHIFD,PRONSPAR                
          RETURN
.
WRPRONH1  RESET     KEY24                                                       
          WRITE     PRIONHA1,KEY24;PRONUNIQ,PRONTDAT,PRONTTIM,PRONUSID,PRONHRSN:
                                   PRONFTXT,PRONACTN,PRONDOCT,PRONPRAC,PRONPIND:
                                   PRONCLAM,PRONHFND,PRONHIFD,PRONSPAR          
          RETURN
.
DEPRONH1  RESET     KEY24                                                       
          DELETE    PRIONHA1,KEY24                                              
          RETURN
.
