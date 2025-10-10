.
. PMSQPXIO    
. --------
. Filename     : pmsqpxaf.dat
.
RSPMQPX1  RESET     KEY20                                                       
          READ      PMSQPXA1,KEY20;;                                            
          RETURN
.
RAPMQPX1  RESET     KEY20                                                       
          MOVE      ZERO,OVRCD
          READ      PMSQPXA1,KEY20;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMQPX1  RESET     KEY20                                                       
          MOVE      ZERO,OVRCD
          READ      PMSQPXA1,KEY20;DPMQXMES,PMPXUDT1,PMPXUTM1,PMPXUDT2,PMPXUTM2:
                                   PMPXUDT3,PMPXUTM3,PMPXUDT4,PMPXUTM4,PMPXUDT5:
                                   PMPXUTM5,PMPXAHC1,PMPXAHG1,PMPXAGC1,PMPXAHC2:
                                   PMPXAHG2,PMPXAGC2,PMPXATF1,PMPXATF2,PMPXATF3:
                                   PMPXATF4,PMPXATF5,PMPXETH1,PMPXETH2,PMPXLAN1:
                                   PMPXLAN2,PMQXSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPMQXMES,PMQXMESI                                           
          RETURN
.
RKPMQPX1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSQPXA1;DPMQXMES,PMPXUDT1,PMPXUTM1,PMPXUDT2,PMPXUTM2:      
                             PMPXUDT3,PMPXUTM3,PMPXUDT4,PMPXUTM4,PMPXUDT5:      
                             PMPXUTM5,PMPXAHC1,PMPXAHG1,PMPXAGC1,PMPXAHC2:
                             PMPXAHG2,PMPXAGC2,PMPXATF1,PMPXATF2,PMPXATF3:
                             PMPXATF4,PMPXATF5,PMPXETH1,PMPXETH2,PMPXLAN1:
                             PMPXLAN2,PMQXSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPMQXMES,PMQXMESI                                           
          RETURN
.
RPPMQPX1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSQPXA1;DPMQXMES,PMPXUDT1,PMPXUTM1,PMPXUDT2,PMPXUTM2:      
                             PMPXUDT3,PMPXUTM3,PMPXUDT4,PMPXUTM4,PMPXUDT5:
                             PMPXUTM5,PMPXAHC1,PMPXAHG1,PMPXAGC1,PMPXAHC2:
                             PMPXAHG2,PMPXAGC2,PMPXATF1,PMPXATF2,PMPXATF3:
                             PMPXATF4,PMPXATF5,PMPXETH1,PMPXETH2,PMPXLAN1:
                             PMPXLAN2,PMQXSPAR
          GOTO      OVERCOND IF OVER
          MOVE      DPMQXMES,PMQXMESI                                           
          RETURN
.
UPPMQPX1  MOVE      ZERO,OVRCD                                                  
          MOVE      PMQXMESI,DPMQXMES                                           
          UPDATE    PMSQPXA1;DPMQXMES,PMPXUDT1,PMPXUTM1,PMPXUDT2,PMPXUTM2:      
                             PMPXUDT3,PMPXUTM3,PMPXUDT4,PMPXUTM4,PMPXUDT5:
                             PMPXUTM5,PMPXAHC1,PMPXAHG1,PMPXAGC1,PMPXAHC2:
                             PMPXAHG2,PMPXAGC2,PMPXATF1,PMPXATF2,PMPXATF3:
                             PMPXATF4,PMPXATF5,PMPXETH1,PMPXETH2,PMPXLAN1:
                             PMPXLAN2,PMQXSPAR
          RETURN
.
WRPMQPX1  RESET     KEY20                                                       
          MOVE      PMQXMESI,DPMQXMES                                           
          WRITE     PMSQPXA1,KEY20;DPMQXMES,PMPXUDT1,PMPXUTM1,PMPXUDT2,PMPXUTM2:
                                   PMPXUDT3,PMPXUTM3,PMPXUDT4,PMPXUTM4,PMPXUDT5:
                                   PMPXUTM5,PMPXAHC1,PMPXAHG1,PMPXAGC1,PMPXAHC2:
                                   PMPXAHG2,PMPXAGC2,PMPXATF1,PMPXATF2,PMPXATF3:
                                   PMPXATF4,PMPXATF5,PMPXETH1,PMPXETH2,PMPXLAN1:
                                   PMPXLAN2,PMQXSPAR
          RETURN
.
DEPMQPX1  RESET     KEY20                                                       
          DELETE    PMSQPXA1,KEY20                                              
          RETURN
.
