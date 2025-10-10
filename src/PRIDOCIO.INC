.
. PRIDOCIO    
. --------
. Filename     : pridocaf.dat
.
RSPRDO1   RESET     KEY22                                                       
          READ      PRIDOCT1,KEY22;;                                            
          RETURN
.
RAPRDO1   RESET     KEY22                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT1,KEY22;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRDO1   RESET     KEY22                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT1,KEY22;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRDO1   MOVE      ZERO,OVRCD                                                  
          READKS    PRIDOCT1;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRDO1   MOVE      ZERO,OVRCD                                                  
          READKP    PRIDOCT1;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRDO1   MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIDOCT1;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          RETURN
.
WRPRDO1   RESET     KEY22                                                       
          WRITE     PRIDOCT1,KEY22;KEY22,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          RETURN
.
DEPRDO1   RESET     KEY22                                                       
          DELETE    PRIDOCT1,KEY22                                              
          RETURN
.
RSPRDO2   RESET     KEY22                                                       
          READ      PRIDOCT2,KEY22;;                                            
          RETURN
.
RAPRDO2   RESET     KEY22                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT2,KEY22;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRDO2   RESET     KEY22                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT2,KEY22;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRDO2   MOVE      ZERO,OVRCD                                                  
          READKS    PRIDOCT2;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRDO2   MOVE      ZERO,OVRCD                                                  
          READKP    PRIDOCT2;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRDO2   MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIDOCT2;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          RETURN
.
WRPRDO2   RESET     KEY22                                                       
          WRITE     PRIDOCT2,KEY22;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          RETURN
.
DEPRDO2   RESET     KEY22                                                       
          DELETE    PRIDOCT2,KEY22                                              
          RETURN
.
RSPRDO3   RESET     KEY32                                                       
          READ      PRIDOCT3,KEY32;;                                            
          RETURN
.
RAPRDO3   RESET     KEY32                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT3,KEY32;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRDO3   RESET     KEY32                                                       
          MOVE      ZERO,OVRCD
          READ      PRIDOCT3,KEY32;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPRDO3   MOVE      ZERO,OVRCD                                                  
          READKS    PRIDOCT3;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPRDO3   MOVE      ZERO,OVRCD                                                  
          READKP    PRIDOCT3;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPRDO3   MOVE      ZERO,OVRCD                                                  
          UPDATE    PRIDOCT3;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          RETURN
.
WRPRDO3   RESET     KEY32                                                       
          WRITE     PRIDOCT3,KEY32;PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:
                                   PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:
                                   PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:
                                   PRDOHLTI,PRDOHLUI,PRDOSPAR                   
          RETURN
.
DEPRDO3   RESET     KEY32                                                       
          DELETE    PRIDOCT3,KEY32                                              
          RETURN
.
.**************************************
. WAssff - Write Audit Record           
. Requires - AUDTTYPE 1=write 
.                     2=before change
.                     3=after change
.                     4=delete
.**************************************
WAPRDO00
          MOVE      "   33",AUDTSECT
          MOVE      " 55",AUDTPOST
          READ      CONTROLF,AUDTSECT;*AUDTPOST,AUDTFLAG
          COMPARE   ONE,AUDTFLAG
          GOTO      WAPRDO99 IF NOT EQUAL
.
          PACK     PRDOAUDD,CCC,CYY,CMM,CDD
          REP       " 0",PRDOAUDD
          CLOCK     TIME,PRDOAUDT
          MOVE      PORT,PRDOAUDP
          LOAD      PRDOAUDR,AUDTTYPE,ANSA,ANSB,ANSC,ANSD
          MOVE      ONE,PRDOAUDS
          MOVE      PASSCODE,PRDOAUDO
          PACK      KEY19,PRDOAUDD,PRDOAUDT,PRDOAUDP,PRDOAUDR
          MOVE      KEY19,AUDTSKEY
          CALL      AWPRDO
WAPRDO99  RETURN
.**************************************
. DAssff - Delete Before Change Audit 
.**************************************
DAPRDO00
          MOVE      "   33",AUDTSECT
          MOVE      " 55",AUDTPOST
          READ      CONTROLF,AUDTSECT;*AUDTPOST,AUDTFLAG
          COMPARE   ONE,AUDTFLAG
          GOTO      DAPRDO99 IF NOT EQUAL
.
          MOVE      AUDTSKEY,KEY19
          CALL      ADPRDO
DAPRDO99  RETURN
ASPRDO    RESET     KEY19                                                       
          READ      PRIAUDDO,KEY19;;                                            
          RETURN
.
AKPRDO                                                                          
          MOVE      ZERO,OVRCD
          READKS    PRIAUDDO;PRDOAUDD,PRDOAUDT,PRDOAUDP,PRDOAUDR,PRDOAUDS:      
                    PRDOAUDO,PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
AUPRDO                                                                          
          UPDATE    PRIAUDDO;PRDOAUDD,PRDOAUDT,PRDOAUDP,PRDOAUDR,PRDOAUDS:      
                    PRDOAUDO,PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          RETURN
.
AWPRDO    RESET     KEY19                                                       
          WRITE     PRIAUDDO,KEY19;KEY19,PRDOAUDS:
                    PRDOAUDO,PRDOPRAC,PRDODOCT,PRDOCLAM,PRDOPIND,PRDOCOMM:      
                             PRDOFEEP,PRDOSTAT,PRDOCRCD,PRDOABNN,PRDOGSTR:      
                             PRDOPROV,PRDOHRSN,PRDOFTXT,PRDOHIFD,PRDOHLDT:      
                             PRDOHLTI,PRDOHLUI,PRDOSPAR                         
          RETURN
.
ADPRDO    RESET     KEY19                                                       
          DELETE    PRIAUDDO,KEY19;                                             
          RETURN
.
