. *****************************************************************************
. *                                                                           *
. *  Include Name :  WATESPIO                                                 *
. *                                                                           *
. *  Function     :  I/O for watespaf file                                    *
. *                                                                           *
. *  Mods         :                                                           *
. *      V11.05.01  06.03.2025 DA Sarkies         TSK 0955909                 *
. *                 Added new field WYEPNDIS                                  *
. *****************************************************************************
.

RSWTESP1  RESET     KEY16                                                       
          READ      WATESPA1,KEY16;;                                            
          RETURN
.
RAWTESP1  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WATESPA1,KEY16;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWTESP1  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WATESPA1,KEY16;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:
                                   WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:
                                   WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:
                                   WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWTESP1  MOVE      ZERO,OVRCD                                                  
          READKS    WATESPA1;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWTESP1  MOVE      ZERO,OVRCD                                                  
          READKP    WATESPA1;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWTESP1  MOVE      ZERO,OVRCD                                                  
          UPDATE    WATESPA1;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          RETURN
.
WRWTESP1  RESET     KEY16                                                       
          WRITE     WATESPA1,KEY16;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:
                                   WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:
                                   WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:
                                   WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR 
          RETURN
.
DEWTESP1  RESET     KEY16                                                       
          DELETE    WATESPA1,KEY16                                              
          RETURN
.
RSWTESP2  RESET     KEY16                                                       
          READ      WATESPA2,KEY16;;                                            
          RETURN
.
RAWTESP2  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WATESPA2,KEY16;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDWTESP2  RESET     KEY16                                                       
          MOVE      ZERO,OVRCD
          READ      WATESPA2,KEY16;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:
                                   WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:
                                   WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:
                                   WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR 
          GOTO      OVERCOND IF OVER
          RETURN
.
RKWTESP2  MOVE      ZERO,OVRCD                                                  
          READKS    WATESPA2;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
RPWTESP2  MOVE      ZERO,OVRCD                                                  
          READKP    WATESPA2;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          GOTO      OVERCOND IF OVER
          RETURN
.
UPWTESP2  MOVE      ZERO,OVRCD                                                  
          UPDATE    WATESPA2;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:      
                             WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:      
                             WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:      
                             WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR       
          RETURN
.
WRWTESP2  RESET     KEY16                                                       
          WRITE     WATESPA2,KEY16;WTEPURNO,WTEPEDAT,WTEPPDOB,WTEPPSEX,WTEPMEDI:
                                   WTEPMREF,WTEPRESI,WTEPPOST,WTEPSUBR,WTEPWEBC:
                                   WTEPCDAT,WTEPCTIM,WTEPWEBU,WTEPUDAT,WTEPUTIM:
                                   WTEPABRG,WTEPEDOB,WTEPPGEN,WTEPNDIS,WTEPSPAR 
          RETURN
.
DEWTESP2  RESET     KEY16                                                       
          DELETE    WATESPA2,KEY16                                              
          RETURN
.
