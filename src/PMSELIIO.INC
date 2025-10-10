.
. PMSELIIO    
. --------
. Filename     : pmseliaf.dat
.
RSPMELI1  RESET     KEY12                                                       
          READ      PMSELIA1,KEY12;;                                            
          RETURN
.
RAPMELI1  RESET     KEY12                                                       
          MOVE      ZERO,OVRCD
          READ      PMSELIA1,KEY12;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMELI1  RESET     KEY12                                                       
          MOVE      ZERO,OVRCD
          READ      PMSELIA1,KEY12;PMEIVISN,PMEIRTYP,PMEICNTR,PMEIITMN,PMEISERV:
                                   PMEIGSTE,PMEIGSTA,PMEIGSTC,PMEIKEYI,PMEIAMNT:
                                   PMEISPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMELI1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSELIA1;PMEIVISN,PMEIRTYP,PMEICNTR,PMEIITMN,PMEISERV:      
                             PMEIGSTE,PMEIGSTA,PMEIGSTC,PMEIKEYI,PMEIAMNT:      
                             PMEISPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMELI1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSELIA1;PMEIVISN,PMEIRTYP,PMEICNTR,PMEIITMN,PMEISERV:      
                             PMEIGSTE,PMEIGSTA,PMEIGSTC,PMEIKEYI,PMEIAMNT:      
                             PMEISPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMELI1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSELIA1;PMEIVISN,PMEIRTYP,PMEICNTR,PMEIITMN,PMEISERV:      
                             PMEIGSTE,PMEIGSTA,PMEIGSTC,PMEIKEYI,PMEIAMNT:      
                             PMEISPAR                                           
          RETURN
.
WRPMELI1  RESET     KEY12                                                       
          WRITE     PMSELIA1,KEY12;PMEIVISN,PMEIRTYP,PMEICNTR,PMEIITMN,PMEISERV:
                                   PMEIGSTE,PMEIGSTA,PMEIGSTC,PMEIKEYI,PMEIAMNT:
                                   PMEISPAR                                     
          RETURN
.
DEPMELI1  RESET     KEY12                                                       
          DELETE    PMSELIA1,KEY12                                              
          RETURN
.
