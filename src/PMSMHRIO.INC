.
. PMSMHRIO    
. --------
. Filename     : pmsmhraf.dat
.
RSPMMHR1  RESET     KEY68                                                       
          READ      PMSMHRA1,KEY68;;                                            
          RETURN
.
RAPMMHR1  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA1,KEY68;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHR1  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA1,KEY68;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHR1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHRA1;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHR1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHRA1;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHR1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHRA1;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          RETURN
.
WRPMMHR1  RESET     KEY68                                                       
          WRITE     PMSMHRA1,KEY68;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          RETURN
.
DEPMMHR1  RESET     KEY68                                                       
          DELETE    PMSMHRA1,KEY68                                              
          RETURN
.
RSPMMHR2  RESET     KEY74                                                       
          READ      PMSMHRA2,KEY74;;                                            
          RETURN
.
RAPMMHR2  RESET     KEY74                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA2,KEY74;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHR2  RESET     KEY74                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA2,KEY74;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHR2  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHRA2;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHR2  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHRA2;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHR2  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHRA2;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          RETURN
.
WRPMMHR2  RESET     KEY74                                                       
          WRITE     PMSMHRA2,KEY74;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          RETURN
.
DEPMMHR2  RESET     KEY74                                                       
          DELETE    PMSMHRA2,KEY74                                              
          RETURN
.
RSPMMHR3  RESET     KEY76                                                       
          READ      PMSMHRA3,KEY76;;                                            
          RETURN
.
RAPMMHR3  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA3,KEY76;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHR3  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA3,KEY76;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHR3  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHRA3;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHR3  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHRA3;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHR3  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHRA3;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          RETURN
.
WRPMMHR3  RESET     KEY76                                                       
          WRITE     PMSMHRA3,KEY76;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          RETURN
.
DEPMMHR3  RESET     KEY76                                                       
          DELETE    PMSMHRA3,KEY76                                              
          RETURN
.
RSPMMHR4  RESET     KEY76                                                       
          READ      PMSMHRA4,KEY76;;                                            
          RETURN
.
RAPMMHR4  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA4,KEY76;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHR4  RESET     KEY76                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA4,KEY76;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHR4  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHRA4;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHR4  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHRA4;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHR4  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHRA4;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          RETURN
.
WRPMMHR4  RESET     KEY76                                                       
          WRITE     PMSMHRA4,KEY76;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          RETURN
.
DEPMMHR4  RESET     KEY76                                                       
          DELETE    PMSMHRA4,KEY76                                              
          RETURN
.
RSPMMHR5  RESET     KEY68                                                       
          READ      PMSMHRA5,KEY68;;                                            
          RETURN
.
RAPMMHR5  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA5,KEY68;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMMHR5  RESET     KEY68                                                       
          MOVE      ZERO,OVRCD
          READ      PMSMHRA5,KEY68;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMMHR5  MOVE      ZERO,OVRCD                                                  
          READKS    PMSMHRA5;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMMHR5  MOVE      ZERO,OVRCD                                                  
          READKP    PMSMHRA5;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMMHR5  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSMHRA5;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:      
                             PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:      
                             PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:      
                             PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:      
                             PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:      
                             PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:      
                             PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR                
          RETURN
.
WRPMMHR5  RESET     KEY68                                                       
          WRITE     PMSMHRA5,KEY68;PMMJRTYP,PMMJCODE,PMMJRDAT,PMMJRTIM,PMMJERRM:
                                   PMMJRCOD,PMMJRDSC,PMMJRDET,PMMJSTAT,PMMJHOSP:
                                   PMMJHOSC,PMMJPAID,PMMJPSID,PMMJSEID,PMMJADAT:
                                   PMMJARES,PMMJDDAT,PMMJRHCP,PMMJAUTH,PMMJETYP:
                                   PMMJELCI,PMMJCONW,PMMJWARD,PMMJROOM,PMMJABED:
                                   PMMJEDTC,PMMJEDTM,PMMJCDAT,PMMJCTIM,PMMJCUID:
                                   PMMJUDAT,PMMJUTIM,PMMJUUID,PMMJSPAR          
          RETURN
.
DEPMMHR5  RESET     KEY68                                                       
          DELETE    PMSMHRA5,KEY68                                              
          RETURN
.
