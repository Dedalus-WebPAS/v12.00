.
. WEBDVWIO    
. --------
. Filename     : webdvwaf.dat
.
RSWBDVW1  RESET     KEY30                                                       
          READ      WEBDVWA1,KEY30;;                                            
          RETURN
.
RAWBDVW1  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA1,KEY30;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW1  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA1,KEY30;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA1;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA1;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW1  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA1;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW1  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY30                                                       
          WRITE     WEBDVWA1,KEY30;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW1  RESET     KEY30                                                       
          DELETE    WEBDVWA1,KEY30                                              
          RETURN
.
RSWBDVW2  RESET     KEY17                                                       
          READ      WEBDVWA2,KEY17;;                                            
          RETURN
.
RAWBDVW2  RESET     KEY17                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA2,KEY17;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW2  RESET     KEY17                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA2,KEY17;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA2;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA2;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW2  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA2;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW2  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY17                                                       
          WRITE     WEBDVWA2,KEY17;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW2  RESET     KEY17                                                       
          DELETE    WEBDVWA2,KEY17                                              
          RETURN
.
RSWBDVW3  RESET     KEY24                                                       
          READ      WEBDVWA3,KEY24;;                                            
          RETURN
.
RAWBDVW3  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA3,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW3  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA3,KEY24;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA3;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA3;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW3  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA3;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW3  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY24                                                       
          WRITE     WEBDVWA3,KEY24;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW3  RESET     KEY24                                                       
          DELETE    WEBDVWA3,KEY24                                              
          RETURN
.UPTOHERE
RSWBDVW4  RESET     KEY24                                                       
          READ      WEBDVWA4,KEY24;;                                            
          RETURN
.
RAWBDVW4  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA4,KEY24;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW4  RESET     KEY24                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA4,KEY24;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA4;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA4;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW4  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA4;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW4  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY24                                                       
          WRITE     WEBDVWA4,KEY24;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW4  RESET     KEY24                                                       
          DELETE    WEBDVWA4,KEY24                                              
          RETURN
.
RSWBDVW5  RESET     KEY35                                                       
          READ      WEBDVWA5,KEY35;;                                            
          RETURN
.
RAWBDVW5  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA5,KEY35;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW5  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA5,KEY35;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW5  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA5;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW5  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA5;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW5  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA5;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW5  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY35                                                       
          WRITE     WEBDVWA5,KEY35;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW5  RESET     KEY35                                                       
          DELETE    WEBDVWA5,KEY35                                              
          RETURN
.
RSWBDVW6  RESET     KEY40                                                       
          READ      WEBDVWA6,KEY40;;                                            
          RETURN
.
RAWBDVW6  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA6,KEY40;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW6  RESET     KEY40                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA6,KEY40;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW6  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA6;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW6  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA6;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW6  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA6;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW6  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY40                                                       
          WRITE     WEBDVWA6,KEY40;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW6  RESET     KEY40                                                       
          DELETE    WEBDVWA6,KEY40                                              
          RETURN
.
RSWBDVW7  RESET     KEY30                                                       
          READ      WEBDVWA7,KEY30;;                                            
          RETURN
.
RAWBDVW7  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA7,KEY30;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVW7  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVWA7,KEY30;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RKWBDVW7  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVWA7;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
RPWBDVW7  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVWA7;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          GOTO      OVERCOND IF OVER
          MOVE      DWBDWFLG,WBDWFLAG
          MOVE      DWBDWEET,WBDWEETP
          RETURN
.
UPWBDVW7  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVWA7;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:      
                             WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:      
                             DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:      
                             WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:      
                             WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:      
                             WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR       
          RETURN
.
WRWBDVW7  MOVE      WBDWFLAG,DWBDWFLG
          MOVE      WBDWEETP,DWBDWEET
          RESET     KEY30                                                       
          WRITE     WEBDVWA7,KEY30;WBDWHOSP,DWBDWFLG,WBDWMODL,WBDWUNIQ,WBDWINVN:
                                   WBDWBATN,WBDWURNO,WBDWPBAT,WBDWNBAT,WBDWTRID:
                                   DWBDWEET,WBDWAMTC,WBDWAMDP,WBDWAMMP,WBDWPDAT:
                                   WBDWSTAT,WBDWCLID,WBDWRKEY,WBDWOKEY,WBDWPRAC:
                                   WBDWMSID,WBDWPROV,WBDWCTYP,WBDWCUID,WBDWCDAT:
                                   WBDWCTIM,WBDWUUID,WBDWUDAT,WBDWUTIM,WBDWSPAR 
          RETURN
.
DEWBDVW7  RESET     KEY30                                                       
          DELETE    WEBDVWA7,KEY30                                              
          RETURN
.
