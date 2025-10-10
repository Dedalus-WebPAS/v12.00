.
. V11.04.02 12/01/2024 TTI C-0932089 Changed file name prihreaf to prihreff
.
. PRIHREIO    
. --------
. Filename     : prihreff.dat
.
RSPRHR1   RESET     KEY27                                                       
          READ      PRIHREF1,KEY27;;                                            
          RETURN
.
RAPRHR1   RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF1,KEY27;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRHR1   RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF1,KEY27;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RKPRHR1   MOVE      ZERO,OVRCD                                                  
          READKS    PRIHREF1;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RPPRHR1   MOVE      ZERO,OVRCD                                                  
          READKP    PRIHREF1;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
UPPRHR1   MOVE      ZERO,OVRCD                                                  
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          UPDATE    PRIHREF1;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          RETURN
.
WRPRHR1   RESET     KEY27                                                       
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          WRITE     PRIHREF1,KEY27;KEY27,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          RETURN
.
DEPRHR1   RESET     KEY27                                                       
          DELETE    PRIHREF1,KEY27                                              
          RETURN
.
RSPRHR2   RESET     KEY28                                                       
          READ      PRIHREF2,KEY28;;                                            
          RETURN
.
RAPRHR2   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF2,KEY28;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRHR2   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF2,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RKPRHR2   MOVE      ZERO,OVRCD                                                  
          READKS    PRIHREF2;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RPPRHR2   MOVE      ZERO,OVRCD                                                  
          READKP    PRIHREF2;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
UPPRHR2   MOVE      ZERO,OVRCD                                                  
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          UPDATE    PRIHREF2;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          RETURN
.
WRPRHR2   RESET     KEY28                                                       
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          WRITE     PRIHREF2,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          RETURN
.
DEPRHR2   RESET     KEY28                                                       
          DELETE    PRIHREF2,KEY28                                              
          RETURN
.
RSPRHR3   RESET     KEY27                                                       
          READ      PRIHREF3,KEY27;;                                            
          RETURN
.
RAPRHR3   RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF3,KEY27;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRHR3   RESET     KEY27                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF3,KEY27;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RKPRHR3   MOVE      ZERO,OVRCD                                                  
          READKS    PRIHREF3;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RPPRHR3   MOVE      ZERO,OVRCD                                                  
          READKP    PRIHREF3;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
UPPRHR3   MOVE      ZERO,OVRCD                                                  
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          UPDATE    PRIHREF3;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          RETURN
.
WRPRHR3   RESET     KEY27                                                       
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          WRITE     PRIHREF3,KEY27;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          RETURN
.
DEPRHR3   RESET     KEY27                                                       
          DELETE    PRIHREF3,KEY27                                              
          RETURN
.
RSPRHR4   RESET     KEY28                                                       
          READ      PRIHREF4,KEY28;;                                            
          RETURN
.
RAPRHR4   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF4,KEY28;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRHR4   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF4,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RKPRHR4   MOVE      ZERO,OVRCD                                                  
          READKS    PRIHREF4;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RPPRHR4   MOVE      ZERO,OVRCD                                                  
          READKP    PRIHREF4;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
UPPRHR4   MOVE      ZERO,OVRCD                                                  
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          UPDATE    PRIHREF4;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          RETURN
.
WRPRHR4   RESET     KEY28                                                       
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          WRITE     PRIHREF4,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          RETURN
.
DEPRHR4   RESET     KEY28                                                       
          DELETE    PRIHREF4,KEY28                                              
          RETURN
.
RSPRHR5   RESET     KEY28                                                       
          READ      PRIHREF5,KEY28;;                                            
          RETURN
.
RAPRHR5   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF5,KEY28;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPRHR5   RESET     KEY28                                                       
          MOVE      ZERO,OVRCD
          READ      PRIHREF5,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RKPRHR5   MOVE      ZERO,OVRCD                                                  
          READKS    PRIHREF5;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
RPPRHR5   MOVE      ZERO,OVRCD                                                  
          READKP    PRIHREF5;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          GOTO      OVERCOND IF OVER
          MOVE      DPRHRUNQ,PRHRUNIQ                                           
          MOVE      DPRHRPIN,PRHRPINV                                           
          RETURN
.
UPPRHR5   MOVE      ZERO,OVRCD                                                  
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          UPDATE    PRIHREF5;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:      
                             PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:      
                             PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:      
                             PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:      
                             PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:      
                             PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:      
                             PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:      
                             PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:      
                             PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:      
                             PRHRSPAR                                           
          RETURN
.
WRPRHR5   RESET     KEY28                                                       
          MOVE      PRHRUNIQ,DPRHRUNQ                                           
          MOVE      PRHRPINV,DPRHRPIN                                           
          WRITE     PRIHREF5,KEY28;DPRHRUNQ,PRHRPRAC,PRHRDOCT,PRHRPIND,PRHRREFD:
                                   PRHRRDAT,PRHRREFT,DPRHRPIN,PRHRMESS,PRHRBULK:
                                   PRHRBCOD,PRHROCOD,PRHRUDF1,PRHRUDF2,PRHRUDF3:
                                   PRHRUDF4,PRHRNAME,PRHRADD1,PRHRADD2,PRHRADD3:
                                   PRHRADD4,PRHRPOST,PRHRTELP,PRHRTELB,PRHRMPHN:
                                   PRHRRELP,PRHRUNCL,PRHRADMN,PRHRRFPD,PRHRTACC:
                                   PRHRLVIS,PRHRACCI,PRHRACPD,PRHRBASS,PRHRISSC:
                                   PRHRSTCD,PRHRFPID,PRHRRPER,PRHRFIDI,PRHRROVR:
                                   PRHRHCPP,PRHRHCGC,PRHRHRSN,PRHRFTXT,PRHRHIFD:
                                   PRHRSPAR                                     
          RETURN
.
DEPRHR5   RESET     KEY28                                                       
          DELETE    PRIHREF5,KEY28                                              
          RETURN
.
