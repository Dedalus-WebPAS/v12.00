.
. WEBDVAIO    
. --------
. Filename     : webdvaaf.dat
.
RSWBDVA1  RESET     KEY27                                                       
          READ      WEBDVAA1,KEY27;;                                            
          RETURN
.
RAWBDVA1  RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA1,KEY27;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVA1  RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA1,KEY27;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVA1  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVAA1;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVA1  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVAA1;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVA1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVAA1;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          RETURN
.
WRWBDVA1  RESET     KEY27                                                       
          WRITE     WEBDVAA1,KEY27;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          RETURN
.
DEWBDVA1  RESET     KEY27                                                       
          DELETE    WEBDVAA1,KEY27                                              
          RETURN
.
RSWBDVA2  RESET     KEY27                                                       
          READ      WEBDVAA2,KEY27;;                                            
          RETURN
.
RAWBDVA2  RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA2,KEY27;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVA2  RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA2,KEY27;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVA2  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVAA2;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVA2  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVAA2;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVA2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVAA2;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          RETURN
.
WRWBDVA2  RESET     KEY27                                                       
          WRITE     WEBDVAA2,KEY27;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          RETURN
.
DEWBDVA2  RESET     KEY27                                                       
          DELETE    WEBDVAA2,KEY27                                              
          RETURN
.
RSWBDVA3  RESET     KEY35                                                       
          READ      WEBDVAA3,KEY35;;                                            
          RETURN
.
RAWBDVA3  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA3,KEY35;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVA3  RESET     KEY35                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA3,KEY35;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVA3  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVAA3;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVA3  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVAA3;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVA3  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVAA3;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          RETURN
.
WRWBDVA3  RESET     KEY35                                                       
          WRITE     WEBDVAA3,KEY35;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          RETURN
.
DEWBDVA3  RESET     KEY35                                                       
          DELETE    WEBDVAA3,KEY35                                              
          RETURN
.
RSWBDVA4  RESET     KEY51                                                       
          READ      WEBDVAA4,KEY51;;                                            
          RETURN
.
RAWBDVA4  RESET     KEY51                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA4,KEY51;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVA4  RESET     KEY51                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA4,KEY51;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVA4  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVAA4;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVA4  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVAA4;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVA4  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVAA4;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          RETURN
.
WRWBDVA4  RESET     KEY51                                                       
          WRITE     WEBDVAA4,KEY51;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          RETURN
.
DEWBDVA4  RESET     KEY51                                                       
          DELETE    WEBDVAA4,KEY51                                              
          RETURN
.
RSWBDVA5  RESET     KEY63                                                       
          READ      WEBDVAA5,KEY63;;                                            
          RETURN
.
RAWBDVA5  RESET     KEY63                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA5,KEY63;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWBDVA5  RESET     KEY63                                                       
          MOVE      ZERO,OVRCD
          READ      WEBDVAA5,KEY63;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWBDVA5  MOVE      ZERO,OVRCD                                                  
          READKS    WEBDVAA5;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWBDVA5  MOVE      ZERO,OVRCD                                                  
          READKP    WEBDVAA5;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWBDVA5  MOVE      ZERO,OVRCD                                                  
          UPDATE    WEBDVAA5;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:      
                             WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:      
                             WBDAMODL,WBDAMSID,WBDASPAR                         
          RETURN
.
WRWBDVA5  RESET     KEY63                                                       
          WRITE     WEBDVAA5,KEY63;WBDAINVN,WBDADATE,WBDATIME,WBDABATN,WBDASTAT:
                                   WBDATYPE,WBDAOPER,WBDATRID,WBDAEROR,WBDAEROT:
                                   WBDAMODL,WBDAMSID,WBDASPAR                   
          RETURN
.
DEWBDVA5  RESET     KEY63                                                       
          DELETE    WEBDVAA5,KEY63                                              
          RETURN
.
