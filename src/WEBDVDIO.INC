.
. WEBDVDIO    
. --------
. Filename     : webdvdaf.dat
.
RSWBDVD1  RESET     KEY33                                                       
          READ      WEBDVDA1,KEY33;;                                            
          RETURN
.
RAWBDVD1  RESET     KEY33                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA1,KEY33;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVD1  RESET     KEY33                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA1,KEY33;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVD1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVDA1;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVD1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVDA1;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVD1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVDA1;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          RETURN
.
WRWBDVD1  RESET     KEY33                                                       
          WRITE     WEBDVDA1,KEY33;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          RETURN
.
DEWBDVD1  RESET     KEY33                                                       
          DELETE    WEBDVDA1,KEY33                                              
          RETURN
.
RSWBDVD2  RESET     KEY57                                                       
          READ      WEBDVDA2,KEY57;;                                            
          RETURN
.
RAWBDVD2  RESET     KEY57                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA2,KEY57;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVD2  RESET     KEY57                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA2,KEY57;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVD2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVDA2;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVD2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVDA2;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVD2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVDA2;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          RETURN
.
WRWBDVD2  RESET     KEY57                                                       
          WRITE     WEBDVDA2,KEY57;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          RETURN
.
DEWBDVD2  RESET     KEY57                                                       
          DELETE    WEBDVDA2,KEY57                                              
          RETURN
.
RSWBDVD3  RESET     KEY69                                                       
          READ      WEBDVDA3,KEY69;;                                            
          RETURN
.
RAWBDVD3  RESET     KEY69                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA3,KEY69;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVD3  RESET     KEY69                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA3,KEY69;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVD3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVDA3;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVD3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVDA3;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVD3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVDA3;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          RETURN
.
WRWBDVD3  RESET     KEY69                                                       
          WRITE     WEBDVDA3,KEY69;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          RETURN
.
DEWBDVD3  RESET     KEY69                                                       
          DELETE    WEBDVDA3,KEY69                                              
          RETURN
.
RSWBDVD4  RESET     KEY33                                                       
          READ      WEBDVDA4,KEY33;;                                            
          RETURN
.
RAWBDVD4  RESET     KEY33                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA4,KEY33;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVD4  RESET     KEY33                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVDA4,KEY33;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVD4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVDA4;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVD4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVDA4;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVD4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVDA4;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:      
                             WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:      
                             WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:      
                             WBDDSPAR                                           
          RETURN
.
WRWBDVD4  RESET     KEY33                                                       
          WRITE     WEBDVDA4,KEY33;WBDDCLID,WBDDRPTC,WBDDCLBP,WBDDCLCA,WBDDSRVP:
                                   WBDDSTAT,WBDDTRID,WBDDMSID,WBDDRKEY,WBDDCUID:
                                   WBDDCDAT,WBDDCTIM,WBDDUUID,WBDDUDAT,WBDDUTIM:
                                   WBDDSPAR                                     
          RETURN
.
DEWBDVD4  RESET     KEY33                                                       
          DELETE    WEBDVDA4,KEY33                                              
          RETURN
.
