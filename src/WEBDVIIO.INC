.
. WEBDVIIO    
. --------
. Filename     : webdviaf.dat
.
RSWBDVI1  RESET     KEY53                                                       
          READ      WEBDVIA1,KEY53;;                                            
          RETURN
.
RAWBDVI1  RESET     KEY53                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA1,KEY53;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVI1  RESET     KEY53                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA1,KEY53;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVI1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVIA1;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVI1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVIA1;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVI1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVIA1;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          RETURN
.
WRWBDVI1  RESET     KEY53                                                       
          WRITE     WEBDVIA1,KEY53;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          RETURN
.
DEWBDVI1  RESET     KEY53                                                       
          DELETE    WEBDVIA1,KEY53                                              
          RETURN
.
RSWBDVI2  RESET     KEY53                                                       
          READ      WEBDVIA2,KEY53;;                                            
          RETURN
.
RAWBDVI2  RESET     KEY53                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA2,KEY53;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVI2  RESET     KEY53                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA2,KEY53;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVI2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVIA2;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVI2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVIA2;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVI2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVIA2;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          RETURN
.
WRWBDVI2  RESET     KEY53                                                       
          WRITE     WEBDVIA2,KEY53;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          RETURN
.
DEWBDVI2  RESET     KEY53                                                       
          DELETE    WEBDVIA2,KEY53                                              
          RETURN
.
RSWBDVI3  RESET     KEY77                                                       
          READ      WEBDVIA3,KEY77;;                                            
          RETURN
.
RAWBDVI3  RESET     KEY77                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA3,KEY77;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVI3  RESET     KEY77                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA3,KEY77;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVI3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVIA3;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVI3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVIA3;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVI3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVIA3;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          RETURN
.
WRWBDVI3  RESET     KEY77                                                       
          WRITE     WEBDVIA3,KEY77;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          RETURN
.
DEWBDVI3  RESET     KEY77                                                       
          DELETE    WEBDVIA3,KEY77                                              
          RETURN
.
RSWBDVI4  RESET     KEY77                                                       
          READ      WEBDVIA4,KEY77;;                                            
          RETURN
.
RAWBDVI4  RESET     KEY77                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA4,KEY77;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVI4  RESET     KEY77                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVIA4,KEY77;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVI4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVIA4;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVI4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVIA4;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVI4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVIA4;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:      
                             WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:      
                             WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR                
          RETURN
.
WRWBDVI4  RESET     KEY77                                                       
          WRITE     WEBDVIA4,KEY77;WBDIHOSP,WBDIPYPN,WBDIPRUN,WBDIPDAT,WBDICLBP:
                                   WBDICLCA,WBDICLID,WBDILDAT,WBDITRID,WBDIRKEY:
                                   WBDISTAT,WBDILTYP,WBDIMSID,WBDISPAR          
          RETURN
.
DEWBDVI4  RESET     KEY77                                                       
          DELETE    WEBDVIA4,KEY77                                              
          RETURN
.
