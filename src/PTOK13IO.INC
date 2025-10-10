. V11.05.00 11/03/2025  Davin       TSK 0956210 - Created ICD10 Ed.13 Opr.KI FD
.
. PTOK13IO    
. --------
. Filename     : patok13f.dat
.
RSOK13A1  RESET     KEY24                                                       
          READ      PTOK13A1,KEY24;;                                            
          RETURN
.
RAOK13A1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTOK13A1,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDOK13A1  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTOK13A1,KEY24;PTCOITM,PTCOKWD,PTCOSPA                      
          GOTO      OVERCOND IF OVER
          RETURN
.
RKOK13A1  MOVE      ZERO,OVRCD
          READKS    PTOK13A1;PTCOITM,PTCOKWD,PTCOSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RPOK13A1  MOVE      ZERO,OVRCD
          READKP    PTOK13A1;PTCOITM,PTCOKWD,PTCOSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
UPOK13A1  UPDATE    PTOK13A1;PTCOITM,PTCOKWD,PTCOSPA                            
          RETURN
.
WROK13A1  RESET     KEY24                                                       
          WRITE     PTOK13A1,KEY24;PTCOITM,PTCOKWD,PTCOSPA                      
          RETURN
.
DEOK13A1  RESET     KEY24                                                       
          DELETE    PTOK13A1,KEY24                                              
          RETURN
.
RSOK13A2  RESET     KEY24                                                       
          READ      PTOK13A2,KEY24;;                                            
          RETURN
.
RAOK13A2  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTOK13A2,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDOK13A2  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      PTOK13A2,KEY24;PTCOITM,PTCOKWD,PTCOSPA                      
          GOTO      OVERCOND IF OVER
          RETURN
.
RKOK13A2  MOVE      ZERO,OVRCD
          READKS    PTOK13A2;PTCOITM,PTCOKWD,PTCOSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RPOK13A2  MOVE      ZERO,OVRCD
          READKP    PTOK13A2;PTCOITM,PTCOKWD,PTCOSPA                            
          GOTO      OVERCOND IF OVER
          RETURN
.
UPOK13A2  UPDATE    PTOK13A2;PTCOITM,PTCOKWD,PTCOSPA                            
          RETURN
.
WROK13A2  RESET     KEY24                                                       
          WRITE     PTOK13A2,KEY24;PTCOITM,PTCOKWD,PTCOSPA                      
          RETURN
.
DEOK13A2  RESET     KEY24                                                       
          DELETE    PTOK13A2,KEY24                                              
          RETURN
.
