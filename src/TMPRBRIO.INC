.
. TMPRBRIO    
. --------
. Filename     : tmprbraf.dat
.
RSTMRBR1  RESET     KEY40                                                       
          READ      TMPRBRA1,KEY40;;                                            
          RETURN
.
RATMRBR1  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      TMPRBRA1,KEY40;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDTMRBR1  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      TMPRBRA1,KEY40;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKTMRBR1  MOVE      ZERO,OVRCD
          READKS    TMPRBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RPTMRBR1  MOVE      ZERO,OVRCD
          READKP    TMPRBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
UPTMRBR1  UPDATE    TMPRBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          RETURN
.
WRTMRBR1  RESET     KEY40                                                       
          WRITE     TMPRBRA1,KEY40;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          RETURN
.
DETMRBR1  RESET     KEY40                                                       
          DELETE    TMPRBRA1,KEY40                                              
          RETURN
.
