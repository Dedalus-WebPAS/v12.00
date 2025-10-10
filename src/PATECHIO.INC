.
. PATECHIO    
. --------
. Filename     : patechaf.dat
.
RSPTECH1  RESET     KEY30                                                       
          READ      PATECHA1,KEY30;;                                            
          RETURN
.
RAPTECH1  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      PATECHA1,KEY30;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPTECH1  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      PATECHA1,KEY30;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:
                                   PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:
                                   PTECHGRP,PTECQNTY,PTECSPAR                   
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
RKPTECH1  MOVE      ZERO,OVRCD                                                  
          READKS    PATECHA1;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
RPPTECH1  MOVE      ZERO,OVRCD                                                  
          READKP    PATECHA1;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
UPPTECH1  MOVE      ZERO,OVRCD                                                  
          MOVE      PTECUNIQ,DPTECUNI
          UPDATE    PATECHA1;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          RETURN
.
WRPTECH1  RESET     KEY30                                                       
          MOVE      PTECUNIQ,DPTECUNI
          WRITE     PATECHA1,KEY30;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:
                                   PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:
                                   PTECHGRP,PTECQNTY,PTECSPAR                   
          RETURN
.
DEPTECH1  RESET     KEY30                                                       
          DELETE    PATECHA1,KEY30                                              
          RETURN
.
RSPTECH2  RESET     KEY30                                                       
          READ      PATECHA2,KEY30;;                                            
          RETURN
.
RAPTECH2  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      PATECHA2,KEY30;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDPTECH2  RESET     KEY30                                                       
          MOVE      ZERO,OVRCD
          READ      PATECHA2,KEY30;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:
                                   PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:
                                   PTECHGRP,PTECQNTY,PTECSPAR                   
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
RKPTECH2  MOVE      ZERO,OVRCD                                                  
          READKS    PATECHA2;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
RPPTECH2  MOVE      ZERO,OVRCD                                                  
          READKP    PATECHA2;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          GOTO      OVERCOND IF OVER
          MOVE      DPTECUNI,PTECUNIQ
          RETURN
.
UPPTECH2  MOVE      ZERO,OVRCD                                                  
          MOVE      PTECUNIQ,DPTECUNI
          UPDATE    PATECHA2;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:      
                             PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:      
                             PTECHGRP,PTECQNTY,PTECSPAR                         
          RETURN
.
WRPTECH2  RESET     KEY30                                                       
          MOVE      PTECUNIQ,DPTECUNI
          WRITE     PATECHA2,KEY30;PTECCTYP,PTECATYP,PTECMBSC,DPTECUNI,PTECEMCH:
                                   PTECOPPC,PTEC1MCF,PTEC2MCF,PTEC3MCF,PTECHFND:
                                   PTECHGRP,PTECQNTY,PTECSPAR                   
          RETURN
.
DEPTECH2  RESET     KEY30                                                       
          DELETE    PATECHA2,KEY30                                              
          RETURN
.
