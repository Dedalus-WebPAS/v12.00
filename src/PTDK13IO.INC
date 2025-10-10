. V11.05.00 11/03/2025  Davin       TSK 0956210 - Created ICD10 Ed.13 Dis.KI FD
.
. PTDK13IO    
. --------
. Filename     : patdk13f.dat
.
RSDK13A1  RESET     KEY24                                                       
          READ      PTDK13A1,KEY24;;                                            
          RETURN
.
RADK13A1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTDK13A1,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDDK13A1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTDK13A1,KEY24;PTCDITM,PTCDKWD,PTCDSPA                      
          GOTO      OVERCOND IF OVER
          RETURN
.
RKDK13A1  MOVE      ZERO,OVRCD
          READKS    PTDK13A1;PTCDITM,PTCDKWD,PTCDSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RPDK13A1  MOVE      ZERO,OVRCD
          READKP    PTDK13A1;PTCDITM,PTCDKWD,PTCDSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
UPDK13A1  UPDATE    PTDK13A1;PTCDITM,PTCDKWD,PTCDSPA                            
          RETURN
.
WRDK13A1  RESET     KEY24                                                       
          WRITE     PTDK13A1,KEY24;PTCDITM,PTCDKWD,PTCDSPA                      
          RETURN
.
DEDK13A1  RESET     KEY24                                                       
          DELETE    PTDK13A1,KEY24                                              
          RETURN
.
RSDK13A2  RESET     KEY24                                                       
          READ      PTDK13A2,KEY24;;                                            
          RETURN
.
RADK13A2  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTDK13A2,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDDK13A2  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTDK13A2,KEY24;PTCDITM,PTCDKWD,PTCDSPA                      
          GOTO      OVERCOND IF OVER
          RETURN
.
RKDK13A2  MOVE      ZERO,OVRCD
          READKS    PTDK13A2;PTCDITM,PTCDKWD,PTCDSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RPDK13A2  MOVE      ZERO,OVRCD
          READKP    PTDK13A2;PTCDITM,PTCDKWD,PTCDSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
UPDK13A2  UPDATE    PTDK13A2;PTCDITM,PTCDKWD,PTCDSPA                            
          RETURN
.
WRDK13A2  RESET     KEY24                                                       
          WRITE     PTDK13A2,KEY24;PTCDITM,PTCDKWD,PTCDSPA                      
          RETURN
.
DEDK13A2  RESET     KEY24                                                       
          DELETE    PTDK13A2,KEY24                                              
          RETURN
.
