.
. TMPIBRIO    
. --------
. Filename     : tmpibraf.dat
.
RSTMIBR1  RESET     KEY40                                                       
          READ      TMPIBRA1,KEY40;;                                            
          RETURN
.
RATMIBR1  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      TMPIBRA1,KEY40;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDTMIBR1  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      TMPIBRA1,KEY40;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKTMIBR1  MOVE      ZERO,OVRCD
          READKS    TMPIBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RPTMIBR1  MOVE      ZERO,OVRCD
          READKP    TMPIBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          GOTO      OVERCOND IF OVER
          RETURN
.
UPTMIBR1  UPDATE    TMPIBRA1;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:      
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          RETURN
.
WRTMIBR1  RESET     KEY40                                                       
          WRITE     TMPIBRA1,KEY40;TEMPHOSP,TEMPCLMC,TEMPCNTR,TEMPFTAB,TEMPCPRC:
                        TEMPEFDT,TEMPBRCD,TEMPAMNT,TEMPSPAR                     
          RETURN
.
DETMIBR1  RESET     KEY40                                                       
          DELETE    TMPIBRA1,KEY40                                              
          RETURN
.
