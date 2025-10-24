.
. IBAPOLIO    
. --------
. Filename     : ibapolaf.dat
.
RSIBPOL1  RESET     KEY10                                                       
          READ      IBAPOLA1,KEY10;;                                            
          RETURN
.
RAIBPOL1  RESET     KEY10                                                       
          MOVE      ZERO,OVRCD
          READ      IBAPOLA1,KEY10;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDIBPOL1  RESET     KEY10                                                       
          MOVE      ZERO,OVRCD
          READ      IBAPOLA1,KEY10;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKIBPOL1  MOVE      ZERO,OVRCD                                                  
          READKS    IBAPOLA1;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPIBPOL1  MOVE      ZERO,OVRCD                                                  
          READKP    IBAPOLA1;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPIBPOL1  MOVE      ZERO,OVRCD                                                  
          UPDATE    IBAPOLA1;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      UPDFLOCK IF LOCKED
          RETURN
.
WRIBPOL1  RESET     KEY10                                                       
          WRITE     IBAPOLA1,KEY10;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          RETURN
.
DEIBPOL1  RESET     KEY10                                                       
          DELETE    IBAPOLA1,KEY10                                              
          RETURN
.
RLIBPOL1  RESET     KEY10                                                       
          MOVE      ZERO,OVRCD
          READL     IBAPOLA1,KEY10;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
KLIBPOL1  MOVE      ZERO,OVRCD                                                  
          READLKS   IBAPOLA1;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
PLIBPOL1  MOVE      ZERO,OVRCD                                                  
          READLKP   IBAPOLA1;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
UUIBPOL1  RESET     KEY10                                                       
          UNLOCK    IBAPOLA1                                                    
          RETURN
.
RSIBPOL2  RESET     KEY21                                                       
          READ      IBAPOLA2,KEY21;;                                            
          RETURN
.
RAIBPOL2  RESET     KEY21                                                       
          MOVE      ZERO,OVRCD
          READ      IBAPOLA2,KEY21;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDIBPOL2  RESET     KEY21                                                       
          MOVE      ZERO,OVRCD
          READ      IBAPOLA2,KEY21;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKIBPOL2  MOVE      ZERO,OVRCD                                                  
          READKS    IBAPOLA2;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPIBPOL2  MOVE      ZERO,OVRCD                                                  
          READKP    IBAPOLA2;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPIBPOL2  MOVE      ZERO,OVRCD                                                  
          UPDATE    IBAPOLA2;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      UPDFLOCK IF LOCKED
          RETURN
.
WRIBPOL2  RESET     KEY21                                                       
          WRITE     IBAPOLA2,KEY21;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          RETURN
.
DEIBPOL2  RESET     KEY21                                                       
          DELETE    IBAPOLA2,KEY21                                              
          RETURN
.
RLIBPOL2  RESET     KEY21                                                       
          MOVE      ZERO,OVRCD
          READL     IBAPOLA2,KEY21;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:
                                   IBPLPSCD,IBPLSPAR                            
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
KLIBPOL2  MOVE      ZERO,OVRCD                                                  
          READLKS   IBAPOLA2;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
PLIBPOL2  MOVE      ZERO,OVRCD                                                  
          READLKP   IBAPOLA2;IBPLUNIQ,IBPLTYPE,IBPLURNO,IBPLVISN,IBPLSKEY:      
                             IBPLPSCD,IBPLSPAR                                  
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
UUIBPOL2  RESET     KEY21                                                       
          UNLOCK    IBAPOLA2                                                    
          RETURN
.
