.
. WEBDVHIO    
. --------
. Filename     : webdvhaf.dat
.
RSWBDVH1  RESET     KEY47                                                       
          READ      WEBDVHA1,KEY47;;                                            
          RETURN
.
RAWBDVH1  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA1,KEY47;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVH1  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA1,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVH1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVHA1;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVH1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVHA1;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVH1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVHA1;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          RETURN
.
WRWBDVH1  RESET     KEY47                                                       
          WRITE     WEBDVHA1,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          RETURN
.
DEWBDVH1  RESET     KEY47                                                       
          DELETE    WEBDVHA1,KEY47                                              
          RETURN
.
RSWBDVH2  RESET     KEY47                                                       
          READ      WEBDVHA2,KEY47;;                                            
          RETURN
.
RAWBDVH2  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA2,KEY47;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVH2  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA2,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVH2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVHA2;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVH2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVHA2;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVH2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVHA2;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          RETURN
.
WRWBDVH2  RESET     KEY47                                                       
          WRITE     WEBDVHA2,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          RETURN
.
DEWBDVH2  RESET     KEY47                                                       
          DELETE    WEBDVHA2,KEY47                                              
          RETURN
.
RSWBDVH3  RESET     KEY48                                                       
          READ      WEBDVHA3,KEY48;;                                            
          RETURN
.
RAWBDVH3  RESET     KEY48                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA3,KEY48;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVH3  RESET     KEY48                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA3,KEY48;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVH3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVHA3;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVH3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVHA3;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVH3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVHA3;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          RETURN
.
WRWBDVH3  RESET     KEY48                                                       
          WRITE     WEBDVHA3,KEY48;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          RETURN
.
DEWBDVH3  RESET     KEY48                                                       
          DELETE    WEBDVHA3,KEY48                                              
          RETURN
.
RSWBDVH4  RESET     KEY47                                                       
          READ      WEBDVHA4,KEY47;;                                            
          RETURN
.
RAWBDVH4  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA4,KEY47;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVH4  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA4,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVH4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVHA4;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVH4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVHA4;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVH4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVHA4;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          RETURN
.
WRWBDVH4  RESET     KEY47                                                       
          WRITE     WEBDVHA4,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          RETURN
.
DEWBDVH4  RESET     KEY47                                                       
          DELETE    WEBDVHA4,KEY47                                              
          RETURN
.
RSWBDVH5  RESET     KEY47                                                       
          READ      WEBDVHA5,KEY47;;                                            
          RETURN
.
RAWBDVH5  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA5,KEY47;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVH5  RESET     KEY47                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVHA5,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVH5  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVHA5;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVH5  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVHA5;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVH5  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVHA5;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:      
                             WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:      
                             WBDHRKEY,WBDHMSID,WBDHSPAR                         
          RETURN
.
WRWBDVH5  RESET     KEY47                                                       
          WRITE     WEBDVHA5,KEY47;WBDHHOSP,WBDHPYPN,WBDHPRUN,WBDHPDAT,WBDHDAMN:
                                   WBDHACCN,WBDHACNM,WBDHBSBC,WBDHSTAT,WBDHRSTA:
                                   WBDHRKEY,WBDHMSID,WBDHSPAR                   
          RETURN
.
DEWBDVH5  RESET     KEY47                                                       
          DELETE    WEBDVHA5,KEY47                                              
          RETURN
.
