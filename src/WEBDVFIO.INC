.
. WEBDVFIO    
. --------
. Filename     : webdvfaf.dat
.
RSWBDVF1  RESET     KEY37                                                       
          READ      WEBDVFA1,KEY37;;                                            
          RETURN
.
RAWBDVF1  RESET     KEY37                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA1,KEY37;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVF1  RESET     KEY37                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA1,KEY37;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVF1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVFA1;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVF1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVFA1;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVF1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVFA1;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          RETURN
.
WRWBDVF1  RESET     KEY37                                                       
          WRITE     WEBDVFA1,KEY37;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          RETURN
.
DEWBDVF1  RESET     KEY37                                                       
          DELETE    WEBDVFA1,KEY37                                              
          RETURN
.
RSWBDVF2  RESET     KEY61                                                       
          READ      WEBDVFA2,KEY61;;                                            
          RETURN
.
RAWBDVF2  RESET     KEY61                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA2,KEY61;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVF2  RESET     KEY61                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA2,KEY61;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVF2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVFA2;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVF2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVFA2;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVF2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVFA2;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          RETURN
.
WRWBDVF2  RESET     KEY61                                                       
          WRITE     WEBDVFA2,KEY61;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          RETURN
.
DEWBDVF2  RESET     KEY61                                                       
          DELETE    WEBDVFA2,KEY61                                              
          RETURN
.
RSWBDVF3  RESET     KEY73                                                       
          READ      WEBDVFA3,KEY73;;                                            
          RETURN
.
RAWBDVF3  RESET     KEY73                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA3,KEY73;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVF3  RESET     KEY73                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA3,KEY73;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVF3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVFA3;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVF3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVFA3;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVF3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVFA3;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          RETURN
.
WRWBDVF3  RESET     KEY73                                                       
          WRITE     WEBDVFA3,KEY73;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          RETURN
.
DEWBDVF3  RESET     KEY73                                                       
          DELETE    WEBDVFA3,KEY73                                              
          RETURN
.
RSWBDVF4  RESET     KEY37                                                       
          READ      WEBDVFA4,KEY37;;                                            
          RETURN
.
RAWBDVF4  RESET     KEY37                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA4,KEY37;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVF4  RESET     KEY37                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVFA4,KEY37;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVF4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVFA4;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVF4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVFA4;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVF4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVFA4;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:      
                             WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:      
                             WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:      
                             WBDFGSTI,WBDFSPAR                                  
          RETURN
.
WRWBDVF4  RESET     KEY37                                                       
          WRITE     WEBDVFA4,KEY37;WBDFCLID,WBDFRPTC,WBDFMEVC,WBDFACRF,WBDFSRVC:
                                   WBDFASSC,WBDFBEPD,WBDFCHAM,WBDFSVID,WBDFITMN:
                                   WBDFNOFP,WBDFPROV,WBDFTRID,WBDFMSID,WBDFRKEY:
                                   WBDFGSTI,WBDFSPAR                            
          RETURN
.
DEWBDVF4  RESET     KEY37                                                       
          DELETE    WEBDVFA4,KEY37                                              
          RETURN
.
