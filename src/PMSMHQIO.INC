.
. PMSMHQIO    
. --------
. Filename     : pmsmhqaf.dat
.
RSPMMHQ1  RESET     KEY68                                                       
          READ      PMSMHQA1,KEY68;;                                            
          RETURN
.
RAPMMHQ1  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA1,KEY68;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ1  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA1,KEY68;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA1;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA1;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA1;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ1  RESET     KEY68                                                       
          WRITE     PMSMHQA1,KEY68;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ1  RESET     KEY68                                                       
          DELETE    PMSMHQA1,KEY68                                              
          RETURN
.
RSPMMHQ2  RESET     KEY74                                                       
          READ      PMSMHQA2,KEY74;;                                            
          RETURN
.
RAPMMHQ2  RESET     KEY74                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA2,KEY74;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ2  RESET     KEY74                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA2,KEY74;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ2  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA2;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ2  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA2;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ2  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA2;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ2  RESET     KEY74                                                       
          WRITE     PMSMHQA2,KEY74;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ2  RESET     KEY74                                                       
          DELETE    PMSMHQA2,KEY74                                              
          RETURN
.
RSPMMHQ3  RESET     KEY76                                                       
          READ      PMSMHQA3,KEY76;;                                            
          RETURN
.
RAPMMHQ3  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA3,KEY76;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ3  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA3,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ3  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA3;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ3  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA3;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ3  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA3;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ3  RESET     KEY76                                                       
          WRITE     PMSMHQA3,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ3  RESET     KEY76                                                       
          DELETE    PMSMHQA3,KEY76                                              
          RETURN
.
RSPMMHQ4  RESET     KEY76                                                       
          READ      PMSMHQA4,KEY76;;                                            
          RETURN
.
RAPMMHQ4  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA4,KEY76;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ4  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA4,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ4  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA4;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ4  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA4;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ4  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA4;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ4  RESET     KEY76                                                       
          WRITE     PMSMHQA4,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ4  RESET     KEY76                                                       
          DELETE    PMSMHQA4,KEY76                                              
          RETURN
.
RSPMMHQ5  RESET     KEY68                                                       
          READ      PMSMHQA5,KEY68;;                                            
          RETURN
.
RAPMMHQ5  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA5,KEY68;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ5  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA5,KEY68;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ5  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA5;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ5  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA5;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ5  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA5;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ5  RESET     KEY68                                                       
          WRITE     PMSMHQA5,KEY68;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ5  RESET     KEY68                                                       
          DELETE    PMSMHQA5,KEY68                                              
          RETURN
.
RSPMMHQ6  RESET     KEY76                                                       
          READ      PMSMHQA6,KEY76;;                                            
          RETURN
.
RAPMMHQ6  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA6,KEY76;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ6  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA6,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ6  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA6;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ6  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA6;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ6  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA6;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ6  RESET     KEY76                                                       
          WRITE     PMSMHQA6,KEY76;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ6  RESET     KEY76                                                       
          DELETE    PMSMHQA6,KEY76                                              
          RETURN
.
RSPMMHQ7  RESET     KEY90                                                       
          READ      PMSMHQA7,KEY90;;                                            
          RETURN
.
RAPMMHQ7  RESET     KEY90                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA7,KEY90;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHQ7  RESET     KEY90                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHQA7,KEY90;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHQ7  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHQA7;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHQ7  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHQA7;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHQ7  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHQA7;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:      
                             PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:      
                             PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:      
                             PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:      
                             PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:      
                             PMMQSPAR                                           
          RETURN
.
WRPMMHQ7  RESET     KEY90                                                       
          WRITE     PMSMHQA7,KEY90;PMMQRTYP,PMMQCODE,PMMQRDAT,PMMQRTIM,PMMQRUID:
                                   PMMQHOSP,PMMQEPID,PMMQADAT,PMMQREAS,PMMQETYP:
                                   PMMQELCY,PMMQCONS,PMMQAUTH,PMMQRHCP,PMMQB64P:
                                   PMMQMIME,PMMQFLNM,PMMQSUBJ,PMMQURNO,PMMQCDAT:
                                   PMMQCTIM,PMMQCUID,PMMQUDAT,PMMQUTIM,PMMQUUID:
                                   PMMQSPAR                                     
          RETURN
.
DEPMMHQ7  RESET     KEY90                                                       
          DELETE    PMSMHQA7,KEY90                                              
          RETURN
.
