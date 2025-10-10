.
. PRIPRAIO    
. --------
. Filename     : pripraaf.dat
.
RSPRPR1   RESET     KEY6                                                        
          READ      PRIPRAC1,KEY6;;                                             
          RETURN
.
RAPRPR1   RESET     KEY6                                                        
          MOVE      ZERO,OVRCD
          READ      PRIPRAC1,KEY6;ANS                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRPR1   RESET     KEY6                                                        
          MOVE      ZERO,OVRCD
          READ      PRIPRAC1,KEY6;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2: 
                                  PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME: 
                                  PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT: 
                                  PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI: 
                                  PRPRHLUI,PRPRSPAR                             
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRPR1   MOVE      ZERO,OVRCD                                                  
          READKS    PRIPRAC1;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRPR1   MOVE      ZERO,OVRCD                                                  
          READKP    PRIPRAC1;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRPR1   MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIPRAC1;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          RETURN
.
WRPRPR1   RESET     KEY6                                                        
          WRITE     PRIPRAC1,KEY6;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2: 
                                  PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME: 
                                  PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT: 
                                  PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI: 
                                  PRPRHLUI,PRPRSPAR                             
          RETURN
.
DEPRPR1   RESET     KEY6                                                        
          DELETE    PRIPRAC1,KEY6                                               
          RETURN
.
RSPRPR2   RESET     KEY36                                                       
          READ      PRIPRAC2,KEY36;;                                            
          RETURN
.
RAPRPR2   RESET     KEY36                                                       
          MOVE      ZERO,OVRCD
          READ      PRIPRAC2,KEY36;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRPR2   RESET     KEY36                                                       
          MOVE      ZERO,OVRCD
          READ      PRIPRAC2,KEY36;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:
                                   PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:
                                   PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:
                                   PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:
                                   PRPRHLUI,PRPRSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRPR2   MOVE      ZERO,OVRCD                                                  
          READKS    PRIPRAC2;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRPR2   MOVE      ZERO,OVRCD                                                  
          READKP    PRIPRAC2;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRPR2   MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIPRAC2;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          RETURN
.
WRPRPR2   RESET     KEY36                                                       
          WRITE     PRIPRAC2,KEY36;PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:
                                   PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:
                                   PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:
                                   PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:
                                   PRPRHLUI,PRPRSPAR                            
          RETURN
.
DEPRPR2   RESET     KEY36                                                       
          DELETE    PRIPRAC2,KEY36                                              
          RETURN
.
.**************************************
. WAssff - Write Audit Record           
. Requires - AUDTTYPE 1=write 
.                     2=before change
.                     3=after change
.                     4=delete
.**************************************
WAPRPR00
          MOVE      "   33",AUDTSECT
          MOVE      " 55",AUDTPOST
          READ      CONTROLF,AUDTSECT;*AUDTPOST,AUDTFLAG
          COMPARE   ONE,AUDTFLAG
          GOTO      WAPRPR99 IF NOT EQUAL
.
          PACK     PRPRAUDD,CCC,CYY,CMM,CDD
          REP       " 0",PRPRAUDD
          CLOCK     TIME,PRPRAUDT
          MOVE      PORT,PRPRAUDP
          LOAD      PRPRAUDR,AUDTTYPE,ANSA,ANSB,ANSC,ANSD
          MOVE      ONE,PRPRAUDS
          MOVE      PASSCODE,PRPRAUDO
          PACK      KEY19,PRPRAUDD,PRPRAUDT,PRPRAUDP,PRPRAUDR
          MOVE      KEY19,AUDTSKEY
          CALL      AWPRPR
WAPRPR99  RETURN
.**************************************
. DAssff - Delete Before Change Audit 
.**************************************
DAPRPR00
          MOVE      "   33",AUDTSECT
          MOVE      " 55",AUDTPOST
          READ      CONTROLF,AUDTSECT;*AUDTPOST,AUDTFLAG
          COMPARE   ONE,AUDTFLAG
          GOTO      DAPRPR99 IF NOT EQUAL
.
          MOVE      AUDTSKEY,KEY19
          CALL      ADPRPR
DAPRPR99  RETURN
ASPRPR    RESET     KEY19                                                       
          READ      PRIAUDPR,KEY19;;                                            
          RETURN
.
AKPRPR                                                                          
          MOVE      ZERO,OVRCD
          READKS    PRIAUDPR;PRPRAUDD,PRPRAUDT,PRPRAUDP,PRPRAUDR,PRPRAUDS:      
                    PRPRAUDO,PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
AUPRPR                                                                          
          UPDATE    PRIAUDPR;PRPRAUDD,PRPRAUDT,PRPRAUDP,PRPRAUDR,PRPRAUDS:      
                    PRPRAUDO,PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          RETURN
.
AWPRPR    RESET     KEY19                                                       
          WRITE     PRIAUDPR,KEY19;PRPRAUDD,PRPRAUDT,PRPRAUDP,PRPRAUDR,PRPRAUDS:
                    PRPRAUDO,PRPRCODE,PRPRDESC,PRPRPDOC,PRPRADD1,PRPRADD2:      
                             PRPRADD3,PRPRPOST,PRPRTELP,PRPRSTAT,PRPRTIME:      
                             PRPRRANG,PRPRPMCI,PRPRPYEE,PRPRREGI,PRPRRDAT:      
                             PRPRHRSN,PRPRFTXT,PRPRHIFD,PRPRHLDT,PRPRHLTI:      
                             PRPRHLUI,PRPRSPAR                                  
          RETURN
.
ADPRPR    RESET     KEY19                                                       
          DELETE    PRIAUDPR,KEY19;                                             
          RETURN
.
