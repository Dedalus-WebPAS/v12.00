.
. PMSFDEIO    
. --------
. Filename     : pmsfdeaf.dat
.
RSPMFDE1  RESET     KEY46                                                       
          READ      PMSFDEA1,KEY46;;                                            
          RETURN
.
RAPMFDE1  RESET     KEY46                                                       
          MOVE      ZERO,OVRCD
          READ      PMSFDEA1,KEY46;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMFDE1  RESET     KEY46                                                       
          MOVE      ZERO,OVRCD
          READ      PMSFDEA1,KEY46;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:
                                   PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:
                                   PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:
                                   PMFECDAT,PMFECTIM,PMFESPRE                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMFDE1  MOVE      ZERO,OVRCD                                                  
          READKS    PMSFDEA1;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMFDE1  MOVE      ZERO,OVRCD                                                  
          READKP    PMSFDEA1;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMFDE1  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSFDEA1;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          RETURN
.
WRPMFDE1  RESET     KEY46                                                       
          WRITE     PMSFDEA1,KEY46;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:
                                   PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:
                                   PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:
                                   PMFECDAT,PMFECTIM,PMFESPRE                   
          RETURN
.
DEPMFDE1  RESET     KEY46                                                       
          DELETE    PMSFDEA1,KEY46                                              
          RETURN
.
RSPMFDE2  RESET     KEY46                                                       
          READ      PMSFDEA2,KEY46;;                                            
          RETURN
.
RAPMFDE2  RESET     KEY46                                                       
          MOVE      ZERO,OVRCD
          READ      PMSFDEA2,KEY46;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPMFDE2  RESET     KEY46                                                       
          MOVE      ZERO,OVRCD
          READ      PMSFDEA2,KEY46;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:
                                   PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:
                                   PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:
                                   PMFECDAT,PMFECTIM,PMFESPRE                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKPMFDE2  MOVE      ZERO,OVRCD                                                  
          READKS    PMSFDEA2;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPPMFDE2  MOVE      ZERO,OVRCD                                                  
          READKP    PMSFDEA2;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPPMFDE2  MOVE      ZERO,OVRCD                                                  
          UPDATE    PMSFDEA2;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:      
                             PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:      
                             PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:      
                             PMFECDAT,PMFECTIM,PMFESPRE                         
          RETURN
.
WRPMFDE2  RESET     KEY46                                                       
          WRITE     PMSFDEA2,KEY46;PMFEHOSP,PMFESYST,PMFESITE,PMFEYEAR,PMFEPERD:
                                   PMFEFTYP,PMFECODE,PMFEINVN,PMFERTYP,PMFETRNO:
                                   PMFEINVD,PMFEURNO,PMFEADMN,PMFEAMNT,PMFECUID:
                                   PMFECDAT,PMFECTIM,PMFESPRE                   
          RETURN
.
DEPMFDE2  RESET     KEY46                                                       
          DELETE    PMSFDEA2,KEY46                                              
          RETURN
.
