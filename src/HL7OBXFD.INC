. V5.06.001 01/12/1998
.*------------------------------------------------------------
.* Include Name  :    HL7OBXFD.INC
.*
.* Function      :    File Definition include for WEB
.*                    HL7 OBX SEGMENT
.*
.* Modifications :
.* V12.00.01 05.06.2025  DA Sarkies     Tsk 0952965
.*           Fixed to create correct task number
.* V11.05.02 05.06.2025  DA Sarkies     Tsk 0952965
.*           Fixed to create correct task number
.* V11.05.01 03.12.2024  DA Sarkies     Tsk 0952965
.*           Increased size of OBX00302 to 50
.* V11.04.02 05.06.2025  DA Sarkies     Tsk 0952965
.*           Fixed to create correct task number
.* V11.04.01 03.12.2024  DA Sarkies     Tsk 0952965
.*           Increased size of OBX00302 to 50
.*
.*------------------------------------------------------------
.
.NAME     TYPE      Length Description
.----     ----      ------ -----------
OBX001    DIM       4      Set ID - Obersvational Simple      
OBX002    DIM       2      Value Type     
OBX003    DIM       127    Observation Identifier   
OBX00301  DIM       10     Type Code
OBX00302  DIM       50     Type Description
OBX00303  DIM       10     Coding System
OBX004    DIM       31     Observation Sub-ID  
OBX00401  DIM       10     Observation Sub-ID code
OBX00402  DIM       20     Onservation Sub-ID description
OBX005    DIM       127    Observation Value 
OBX006    DIM       20     Units      
OBX007    DIM       20     Reference Range      
OBX008    DIM       5      Abnormal Flag      
OBX009    DIM       5      Probability      
OBX010    DIM       2      Nature of Abnormal Test      
OBX011    DIM       2      Observation Result Status      
OBX012    DIM       1      NS:Date Last Obs Normal Values     
OBX013    DIM       1      NS:User Defined Access Checks   
OBX014    DIM       13     Date-Time of Observation
OBX01401  DIM       8      Date Observation
OBX01402  DIM       5      Time of Observation
OBX015    DIM       25     Performer ID
OBX016    DIM       25     Responsible Observer
OBX017    DIM       60     Observation Method
