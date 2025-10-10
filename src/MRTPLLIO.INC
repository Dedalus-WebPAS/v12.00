.
. MRTPLLIO    
. --------
. Filename     : mrtpllaf.dat
.
RSMRPLL1  RESET     KEY20                                                       
          READ      MRTPLLA1,KEY20;;                                            
          RETURN
.
RAMRPLL1  RESET     KEY20                                                       
          MOVE      ZERO,OVRCD
          READ      MRTPLLA1,KEY20;ANS                                          
          GOTO      OVERCOND IF OVER
          RETURN
.
RDMRPLL1  RESET     KEY20                                                       
          MOVE      ZERO,OVRCD
          READ      MRTPLLA1,KEY20;MRPLVISN,MRPLMRKY,MRPLRQST,MRPLCUID,MRPLCDAT:
                                   MRPLCTIM,MRPLUUID,MRPLUDAT,MRPLUTIM,MRPLUDF1:
                                   MRPLUDF2,MRPLUDC1,MRPLUDC2,MRPLFTX1,MRPLFTX2:
                                   MRPLSPAR                                     
          GOTO      OVERCOND IF OVER
          RETURN
.
RKMRPLL1  MOVE      ZERO,OVRCD                                                  
          READKS    MRTPLLA1;MRPLVISN,MRPLMRKY,MRPLRQST,MRPLCUID,MRPLCDAT:      
                             MRPLCTIM,MRPLUUID,MRPLUDAT,MRPLUTIM,MRPLUDF1:      
                             MRPLUDF2,MRPLUDC1,MRPLUDC2,MRPLFTX1,MRPLFTX2:      
                             MRPLSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
RPMRPLL1  MOVE      ZERO,OVRCD                                                  
          READKP    MRTPLLA1;MRPLVISN,MRPLMRKY,MRPLRQST,MRPLCUID,MRPLCDAT:      
                             MRPLCTIM,MRPLUUID,MRPLUDAT,MRPLUTIM,MRPLUDF1:      
                             MRPLUDF2,MRPLUDC1,MRPLUDC2,MRPLFTX1,MRPLFTX2:      
                             MRPLSPAR                                           
          GOTO      OVERCOND IF OVER
          RETURN
.
UPMRPLL1  MOVE      ZERO,OVRCD                                                  
          UPDATE    MRTPLLA1;MRPLVISN,MRPLMRKY,MRPLRQST,MRPLCUID,MRPLCDAT:      
                             MRPLCTIM,MRPLUUID,MRPLUDAT,MRPLUTIM,MRPLUDF1:      
                             MRPLUDF2,MRPLUDC1,MRPLUDC2,MRPLFTX1,MRPLFTX2:      
                             MRPLSPAR                                           
          RETURN
.
WRMRPLL1  RESET     KEY20                                                       
          WRITE     MRTPLLA1,KEY20;MRPLVISN,MRPLMRKY,MRPLRQST,MRPLCUID,MRPLCDAT:
                                   MRPLCTIM,MRPLUUID,MRPLUDAT,MRPLUTIM,MRPLUDF1:
                                   MRPLUDF2,MRPLUDC1,MRPLUDC2,MRPLFTX1,MRPLFTX2:
                                   MRPLSPAR                                     
          RETURN
.
DEMRPLL1  RESET     KEY20                                                       
          DELETE    MRTPLLA1,KEY20                                              
          RETURN
.
