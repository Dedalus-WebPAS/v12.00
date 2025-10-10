.
. PATDDHIO    
. --------
. Filename     : patddhaf.dat
.
RSPTDDH1  RESET     KEY17                                                       
          READ      PATDDHA1,KEY17;;                                            
          RETURN
.
RAPTDDH1  RESET     KEY17                                                       
          MOVE      ZERO,OVRCD
          READ      PATDDHA1,KEY17;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPTDDH1  RESET     KEY17                                                       
          MOVE      ZERO,OVRCD
          READ      PATDDHA1,KEY17;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:
                                   PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:
                                   PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:
                                   PTDDDLEN,PTDDSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPTDDH1  MOVE      ZERO,OVRCD                                                  
          READKS    PATDDHA1;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:      
                             PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:      
                             PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:      
                             PTDDDLEN,PTDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPTDDH1  MOVE      ZERO,OVRCD                                                  
          READKP    PATDDHA1;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:      
                             PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:      
                             PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:      
                             PTDDDLEN,PTDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPTDDH1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PATDDHA1;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:      
                             PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:      
                             PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:      
                             PTDDDLEN,PTDDSPAR                                           
          GOTO      UPDFLOCK IF LOCKED
          RETURN
.
WRPTDDH1  RESET     KEY17                                                       
          WRITE     PATDDHA1,KEY17;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:
                                   PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:
                                   PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:
                                   PTDDDLEN,PTDDSPAR                                  
          RETURN
.
DEPTDDH1  RESET     KEY17                                                       
          DELETE    PATDDHA1,KEY17                                              
          RETURN
.
RLPTDDH1  RESET     KEY17                                                       
          MOVE      ZERO,OVRCD
          READL     PATDDHA1,KEY17;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:
                                   PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:
                                   PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:
                                   PTDDDLEN,PTDDSPAR                                     
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
KLPTDDH1  MOVE      ZERO,OVRCD                                                  
          READLKS   PATDDHA1;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:      
                             PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:      
                             PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:      
                             PTDDDLEN,PTDDSPAR                                           
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
PLPTDDH1  MOVE      ZERO,OVRCD                                                  
          READLKP   PATDDHA1;PTDDFUND,PTDDFTYP,PTDDDTTO,PTDDFLD1,PTDDFLD2:      
                             PTDDCFD1,PTDDCFD2,PTDDFVL1,PTDDFVL2,PTDDCRBY:      
                             PTDDCRDT,PTDDCRTM,PTDDUPBY,PTDDUPDT,PTDDUPTM:      
                             PTDDDLEN,PTDDSPAR                                           
          GOTO      OVERCOND IF OVER
          GOTO      OVERLOCK IF LOCKED
          RETURN
.
UUPTDDH1  RESET     KEY17                                                       
          UNLOCK    PATDDHA1                                                    
          RETURN
.
