.  ************************************************************************
.  *                                                                      *
.  *  Include Name      :   EMRQUEFD.INC                                  *
.  *                                                                      *
.  *  Function          :   Queuing Emergency Visit Details Message File  *
.  *                                                                      *
.  *  File Type         :   SQL                                           *
.  *                                                                      *
.  *  File Name         :   emrqueaf.dat                                  *
.  *                                                                      *
.  *  Keys              :   KEY20                                         *
.  *                                                                      *
.  *  Modifications     :                                                 *
.  ************************************************************************
.  * V12.00.01 08/05/2025 Thanh T     TSK 0955096                         *
.  *           Changed EMVIADMN from FORM(8) to DIM(8)                    *
.  ************************************************************************
.  *  V11.04.01 04/12/2023  Thanh T            TSK 0936282                *
.  *            Changed EMVIHFMN size from 10 to 19 and EMQUSPAR from 71  *
.  *            to 62                                                     *
.  ************************************************************************
.  *  V10.13.01 08/10/2018  Steve Armstrong    TSK 0860677                *
.  *            Added new variables EMVIUC31 to EMVIBNAA (including       *
.  *            moving EMVIBNAA from the SPARE variable into a normal     *
.  *            FD field.                                                 *
.  *            02/10/2018  Thanh T            TSK 0859743                *
.  *            Added EMVIBNAA                                            *
.  ************************************************************************
.  *  V10.12.01 05/06/2018  Davin              TSK 0851377                *
.  *            Added EMVIUC31,EMVIUC32,EMVIUC33,EMVIUC34,EMVIUC35        *
.  ************************************************************************
.  *  V10.05.02 20/08/2014  Steve Armstrong    CAR 303879                 *
.  *            Extended Ambulance Case Number (EMVIAMBL) from DIM6 to    *
.  *            DIM15.                                                    *
.  *  V10.05.01 13/08/2014  Ania P             CAR 303879                 *
.  *            Added/Moved fields (out of SPARE): EMVIPRLO - EMVIMDTM    *
.  *  V10.04.01 11/03/2014  Ebon Clements      CAR 294181                 *
.  *            Added EMVIAADT to EMVIDATM stored in spare                *
.  *  V9.09.01  26/10/2007  Peter Vela         CAR 151159                 *
.  *            Added Status 4 Cancelled                                  *
.  *  V9.02.00  08/01/2002  Davin                                         * 
.  *            FD Created                                                *
.  *                                                                      *
.  ************************************************************************
.
.Data File Definition
.--------------------
EMRQUEA1   IFILE SQL, FIXED=1647, KEY="U1-20"
.
.Name      Type   Length  Physical Start Description
.----      ----   ------  -------- ----- -----------
DEMQUMES   DIM       20     20       1     Message Id
.
.          EMRVISFD variables
.
.EMVIADMN  DIM       8      8        21    Visit Number                       
.EMVISTAT  FORM      1      2        29    Status                             
.                                              1 = Current Patient
.                                              2 = Discharged Incomplete
.                                              3 = Discharged Complete
.                                              4 = Cancelled
.EMVIURNO  DIM       8      8        31    Patient U/R Number                 
.EMVIDATE  DIM       8      8        39    Arrival Date (CCYYMMDD)            
.EMVITIME  DIM       8      8        47    Arrival Time (HH:MM:SS)            
.EMVITRIG  DIM       3      3        55    Triage Code (category AA)          
.EMVICOM1  DIM       50     50       58    Complaint Line 1                   
.EMVICOM2  DIM       50     50       108   Complaint Line 2                   
.EMVILOCN  DIM       3      3        158   Location (emrlocaf)                
.EMVIDOCT  DIM       10     10       161   Attending Doctor                   
.EMVICOMP  DIM       3      3        171   Compensation Code (category CL)    
.EMVICLAS  DIM       3      3        174   Patient Classification (category A)
.EMVIINSR  DIM       3      3        177   Insurance Status (category U1)     
.EMVISRCE  DIM       3      3        180   Source of Referal (category S)     
.EMVISITN  DIM       3      3        183   Situation (category ES)            
.EMVIMODE  DIM       3      3        186   Mode of Arrival (category EA)      
.EMVIADMT  FORM      1      2        189   Admitted to Hospital               
.                                          0 = No
.                                          1 = Yes
.EMVIDURN  FORM      4      3        191   Duration of Waiting (in minutes)   
.EMVIEMPL  DIM       20     20       194   Employer (Workcover)               
.EMVIWAIT  DIM       3      3        214   Completion Wait Code (category EW) 
.EMVIPREV  DIM       3      3        217   Previous A&E Attendance (cat. EP)  
.EMVIFUND  DIM       6      6        220   Health Fund                        
.EMVITABL  DIM       8      8        226   Health Fund Table                  
.EMVIREFG  DIM       10     10       234   Referring GP                       
.EMVIREFD  DIM       10     10       244   Referring Doctor                   
.EMVIPLIN  DIM       3      3        254   Place of Incident (category AP)    
.EMVIINIT  DIM       3      3        257   Initiator (category AI)            
.EMVIRTAS  DIM       3      3        260   RTA Seatbelt Details (category AR) 
.EMVIDDAT  DIM       8      8        263   Discharge Date (CCYYMMDD)          
.EMVIDTIM  DIM       8      8        271   Discharge Time (HH:MM:SS)          
.EMVIDSTA  DIM       3      3        279   Discharge Status (category ED)     
.EMVIOPR1  DIM       10     10       282   Web Operator - event (websecaf)    
.EMVIOPR2  DIM       10     10       292   Web Operator - discharge (websecaf)
.EMVIUC01  DIM       3      3        302   User Defined Code 1  (category A1) 
.EMVIUC02  DIM       3      3        305   User Defined Code 2  (category A2) 
.EMVIUC03  DIM       3      3        308   User Defined Code 3  (category A3) 
.EMVIUC04  DIM       3      3        311   User Defined Code 4  (category A4) 
.EMVIUC05  DIM       3      3        314   User Defined Code 5  (category A5) 
.EMVIUC06  DIM       3      3        317   User Defined Code 6  (category A6) 
.EMVIUC07  DIM       3      3        320   User Defined Code 7  (category A7) 
.EMVIUC08  DIM       3      3        323   User Defined Code 8  (category A8) 
.EMVIUC09  DIM       3      3        326   Transport Mode       (category ea) 
.EMVIUC10  DIM       3      3        329   Escort Source        (category eb) 
.EMVIUC11  DIM       3      3        332   Referred to on Disch (category ec) 
.EMVIUC12  DIM       3      3        335   Reason for Transfer  (category ed) 
.EMVIUC13  DIM       3      3        338   Type of Visit        (category ee) 
.EMVIUC14  DIM       3      3        341   Human Intent         (category ef) 
.EMVIUC15  DIM       3      3        344   Activity when Injured(category eg) 
.EMVIUC16  DIM       3      3        347   Nurse Code           (category eh) 
.EMVIUC17  DIM       3      3        350   Injury Cause         (category ei) 
.EMVIUC18  DIM       3      3        353   User Defined Code 18 (category ej) 
.EMVIUC19  DIM       3      3        356   User Defined Code 19 (category ek) 
.EMVIUC20  DIM       3      3        359   Presenting Complaint (category el) 
.EMVIUC21  DIM       3      3        362   User Defined Code 21 (category em) 
.EMVIUC22  DIM       3      3        365   User Defined Code 22 (category en) 
.EMVIUC23  DIM       3      3        368   User Defined Code 23 (category eo) 
.EMVIUC24  DIM       3      3        371   User Defined Code 24 (category ep) 
.EMVIUC25  DIM       3      3        374   User Defined Code 25 (category eq) 
.EMVIUC26  DIM       3      3        377   User Defined Code 26 (category er) 
.EMVIUC27  DIM       3      3        380   User Defined Code 27 (category es) 
.EMVIUC28  DIM       3      3        383   User Defined Code 28 (category et) 
.EMVIUC29  DIM       3      3        386   User Defined Code 20 (category eu) 
.EMVIUC30  DIM       3      3        389   User Defined Code 30 (category ev) 
.EMVIUD01  DIM       8      8        392   User Defined Date 1  (CCYYMMDD)    
.EMVIUD02  DIM       8      8        400   User Defined Date 2  (CCYYMMDD)    
.EMVIUD03  DIM       8      8        408   User Defined Date 3  (CCYYMMDD)    
.EMVIUD04  DIM       8      8        416   User Defined Date 4  (CCYYMMDD)    
.EMVIUD05  DIM       8      8        424   User Defined Date 5  (CCYYMMDD)    
.EMVIUD06  DIM       8      8        432   User Defined Date 6  (CCYYMMDD)    
.EMVIUD07  DIM       8      8        440   User Defined Date 7  (CCYYMMDD)    
.EMVIUD08  DIM       8      8        448   User Defined Date 8  (CCYYMMDD)    
.EMVIUD09  DIM       8      8        456   User Defined Date 9  (CCYYMMDD)    
.EMVIUD10  DIM       8      8        464   User Defined Date 10 (CCYYMMDD)    
.EMVIUT01  DIM       8      8        472   User Defined Time 1  (CCYYMMDD)    
.EMVIUT02  DIM       8      8        480   User Defined Time 2  (HH:MM:SS)    
.EMVIUT03  DIM       8      8        488   User Defined Time 3  (HH:MM:SS)    
.EMVIUT04  DIM       8      8        496   User Defined Time 4  (HH:MM:SS)    
.EMVIUT05  DIM       8      8        504   User Defined Time 5  (HH:MM:SS)    
.EMVIUT06  DIM       8      8        512   User Defined Time 6  (HH:MM:SS)    
.EMVIUT07  DIM       8      8        520   User Defined Time 7  (HH:MM:SS)    
.EMVIUT08  DIM       8      8        528   User Defined Time 8  (HH:MM:SS)    
.EMVIUT09  DIM       8      8        536   User Defined Time 9  (HH:MM:SS)    
.EMVIUT10  DIM       8      8        544   User Defined Time 10 (HH:MM:SS)    
.EMVIYN01  FORM      1      2        552   User Defined Y/N Field 1           
.                                          0 = No
.                                          1 = Yes
.EMVIYN02  FORM      1      2        554   User Defined Y/N Field 2           
.                                          0 = No
.                                          1 = Yes
.EMVIYN03  FORM      1      2        556   User Defined Y/N Field 3           
.                                          0 = No
.                                          1 = Yes
.EMVIYN04  FORM      1      2        558   User Defined Y/N Field 4           
.                                          0 = No
.                                          1 = Yes
.EMVIYN05  FORM      1      2        560   User Defined Y/N Field 5           
.                                          0 = No
.                                          1 = Yes
.EMVIYN06  FORM      1      2        562   User Defined Y/N Field 6           
.                                          0 = No
.                                          1 = Yes
.EMVIYN07  FORM      1      2        564   User Defined Y/N Field 7           
.                                          0 = No
.                                          1 = Yes
.EMVIYN08  FORM      1      2        566   User Defined Y/N Field 8           
.                                          0 = No
.                                          1 = Yes
.EMVIYN09  FORM      1      2        568   User Defined Y/N Field 9           
.                                          0 = No
.                                          1 = Yes
.EMVIYN10  FORM      1      2        570   Ongoing Care Communication         
.                                          0 = No
.                                          1 = Yes
.EMVITXT1  DIM       50     50       572   User Defined Text Field 1          
.EMVITXT2  DIM       50     50       622   User Defined Text Field 2          
.EMVITXT3  DIM       50     50       672   User Defined Text Field 3          
.EMVITXT4  DIM       50     50       722   User Defined Text Field 4          
.EMVITXT5  DIM       50     50       772   User Defined Text Field 5          
.EMVIUN01  FORM      6      4        822   User Defined Numeric Field 1       
.EMVIUN02  FORM      6      4        826   User Defined Numeric Field 2       
.EMVIUN03  FORM      6      4        830   User Defined Numeric Field 3       
.EMVIUN04  FORM      6      4        834   User Defined Numeric Field 4       
.EMVIUN05  FORM      6      4        838   User Defined Numeric Field 5       
.EMVIELAP  DIM       3      3        842   Elapsed Since Accident (cat. AE)   
.EMVINSDT  DIM       8      8        845   Date First Seen by Nurse (CCYYMMDD)
.EMVINSTM  DIM       8      8        853   Time First Seen by Nurse (HH:MM:SS)
.EMVIDRDT  DIM       8      8        861   Date First Seen by Doct. (CCYYMMDD)
.EMVIDRTM  DIM       8      8        869   Time First Seen by Doct. (HH:MM:SS)
.EMVIPATT  FORM      3      3        877   Number of Previous Attendences     
.EMVITSRC  DIM       5      5        880   Transfer Source Code               
.EMVIDEST  DIM       5      5        885   Discharge Destination Code         
.EMVIAMBL  DIM       15     15       890   Ambulance Case Number              
.EMVIREGN  DIM       2      2        905   Body Region                        
.EMVISENT  DIM       1      1        907   Extract Sent                       
.                                          0 = No
.                                          1 = Yes
.EMVIUR01  DIM       6      6        908   User Defined Doctor Field 1        
.EMVIUR02  DIM       6      6        914   User Defined Doctor Field 2        
.EMVIUR03  DIM       6      6        920   User Defined Doctor Field 3        
.EMVIUR04  DIM       6      6        926   User Defined Doctor Field 4        
.EMVIUR05  DIM       6      6        932   User Defined Doctor Field 5        
.EMVIPADM  DIM       8      8        938   Patient System Admission Number    
.                                          (if admitted to hospital)
.EMVIEWRD  DIM       3      3        946   Expected Ward (Patient System)     
.EMVIEBED  DIM       3      3        949   Expected Bed  (Patient System)     
.EMVIHFMN  DIM       19     19       952   Health Fund Member Number          
.EMVIACLS  DIM       3      3        971   Admission Class (category P)       
.EMVICCLS  DIM       3      3        974   Care Class      (category CC)      
.EMVITRNS  DIM       10     10       977   Triage Nurse                       
.EMVIDUM1  DIM       3      3        987   Dummy Field 1                      
.EMVITRDT  DIM       8      8        990   Triage Date                        
.EMVITRTM  DIM       8      8        998   Triage Time                        
.EMVIATNS  DIM       10     10       1006  Attending Nurse                    
.EMVIDUM2  DIM       3      3        1016  Dummy Field 2                      
.EMVIEXLC  DIM       3      3        1019  External Location Code (emrlocaf)  
.EMVISITE  DIM       3      3        1022  Emergency Site Code                
.EMVIUNIT  DIM       3      3        1025  Unit (category AC)                 
.EMVICOM3  DIM       50     50       1028  Complaint Line 3                   
.EMVICOM4  DIM       50     50       1078  Complaint Line 4                   
.EMVICOM5  DIM       50     50       1128  Complaint Line 5                   
.EMVICOM6  DIM       50     50       1178  Complaint Line 6                   
.EMVIINJ1  DIM       50     50       1228  Injury Description Line 1          
.EMVIINJ2  DIM       50     50       1278  Injury Description Line 2          
.EMVINATI  DIM       3      3        1328  Nature of Main Injury (category ex)
.EMVIINJC  DIM       3      3        1331  Injury Cause          (category ey)
.EMVIHUMI  DIM       3      3        1334  Human Intent          (category ez)
.EMVIACTI  DIM       3      3        1337  Activity When Injured (category EY)
.EMVILOCO  DIM       25     25       1340  Other Location Description         
.EMVIPRLO  DIM       3      3        1365  Previous Location (emrlocaf)
.EMVIPRTM  DIM       8      8        1368  Time Left Previous Location (hh:mm:
.EMVIDPDT  DIM       8      8        1376 Departure Date (CCYYMMDD)
.EMVIDPTM  DIM       8      8        1384  Departure Time (HH:MM:SS)
.EMVIEXRS  DIM       3      3        1392  Extended Visit Reason (Cat RX)
.EMVIDLRS  DIM       3      3        1395  Departure Delay Reason (Cat RY)
.EMVISPDT  DIM       8      8        1398  Speciality Date (CCYYMMDD)
.EMVISPTM  DIM       8      8        1406  Speciality Time (HH:MM:SS)
.EMVISADT  DIM       8      8        1414  Speciality Arrival Date (CCYYMMDD)
.EMVISATM  DIM       8      8        1422  Speciality Arrival Time (HH:MM:SS)
.EMVIMPRA  DIM       10     10       1430  Mental Health Practitioner (pmshcpa
.EMVIMPDT  DIM       8      8        1440  Date First Seen by MH Prac.(CCYYMMD
.EMVIMPTM  DIM       8      8        1448  Time First Seen by MH Prac.(HH:MM:S
.EMVIAADT  DIM       8      8        1456  Ambulance Arrival Date (CCYYMMDD)
.EMVIAATM  DIM       8      8        1464  Ambulance Arrival Time (HH:MM:SS)
.EMVIAHDT  DIM       8      8        1472  Ambulance Handover Date (CCYYMMDD)
.EMVIAHTM  DIM       8      8        1480  Ambulance Handover Time (HH:MM:SS)
.EMVIDADT  DIM       8      8        1488  Decision to Admit Date (CCYYMMDD)
.EMVIDATM  DIM       8      8        1496  Decision to Admit Time (HH:MM:SS)
.EMVIPURC  DIM       3      3        1504  Health Purchaser (Cat HP)
.EMVIMNCD  DIM       10     10       1507  Meet & Greet Assessment Nurse Code
.EMVIMNDT  DIM       8      8        1517  Meet & Greet Ass. Nurse Date Seen
.EMVIMNTM  DIM       8      8        1525  Meet & Greet Ass. Nurse Time Seen
.EMVIMDCD  DIM       10     10       1533  Meet & Greet Ass. Doctor Code
.EMVIMDDT  DIM       8      8        1543  Meet & Greet Ass. Doctor Date Seen
.EMVIMDTM  DIM       8      8        1551  Meet & Greet Ass. Doctor Time Seen
.EMVIUC31  DIM       3      3        1559  User Defined Code 31 (category YN)
.EMVIUC32  DIM       3      3        1562  Call Attempt 2 Status (category YO)
.EMVIUC33  DIM       3      3        1565  Call Attempt 3 Status (category YP)
.EMVIUC34  DIM       3      3        1568  Patient Follow Up Outcome(categoryYQ)
.EMVIUC35  DIM       3      3        1571  Call Attempt 1 Status (category YR)
.EMVIREFP  DIM       3      3        1574  Referral Period (Category RF)
.EMVIREPM  DIM       2      2        1577  Referring Period Month
.                                          (1-98 months, right justified)
.EMVIREDT  DIM       8      8        1579 Referral Date
.EMVIBNAA  DIM       1      1        1587  Benefit Assignment Authorised
.                                          0 or Blank - No
.                                          1 - Yes
EMQUSPAR  DIM       59     59       1588  Spare Variables                    
.
.End of Record                       1647 
.
.
.Redefine FORM fields from key
.-----------------------------
EMQUMESI   FORM      20
