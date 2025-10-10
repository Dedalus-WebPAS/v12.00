. *----------------------------------------------------------------------
. * Include Name  :   PATCRDFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Cancer Registration Details        
. *
. * File Type     :   SQL
. *
. * File Name     :   patcrdaf.dat
. * Keys          :   Key 25 - PATCRDA1
. *
. * Modifications :   
. *----------------------------------------------------------------------
. * V12.00.01 29/04/2025 Thanh T     TSK 0955096 
. *           Changed PTCDDADN from FORM(8) to DIM(8)
. *----------------------------------------------------------------------
. *    V11.04.02    24/01/2024  Ebon Clements    TSK 0939233
. *                 Added PTCDFCPR usage                            
. *    V11.04.01    20/11/2023  Thanh T          TSK 0939233
. *                 Changed PTCDFCPR size from 75 to 250 and PTCDSPAR
. *                 size from 37 to 50.  
. *----------------------------------------------------------------------
. *    V10.12.02    19/03/2018  Jill Parkinson   TSK 0848131
. *                 Added index 3 and 4
. *    V10.12.01    08/03/2018  J.Tan            TSK 0842287
. *                 Added 'Best Basis for Diagnosis' cat 'Bd'
. *    V10.08.02    13/05/2016  J.Tan            TSK 0315587
. *                 Changed desc.for PTCDSTAG
. *    V10.08.01    12/04/2016  Steve Armstrong  TSK 0813958
. *                 Added PTCDSCFL & PTCDCSSY
. *    V10.07.01    20/10/2015  Ebon Clements    CAR 315587
. *                 Changed PTCDRADI and PTCDSYST from Cat QE to QF
. *    V10.06.01    16/04/2015  Steve Armstrong  CAR 315587
. *                 Added PTCDRADI & PTCDSYST and reduced spare
. *    V10.04.01    27/12/2013  Patrick Adair  CAR 294433
. *                 Moved PTCDECOG out of spare
. *    V10.03.01    03/06/2013  Davin          CAR 283509
. *                 Added PTCDECOG to spare
. *    V10.00.01    29/03/2010  Mike Laming    CAR 208570
. *                 PTCDMET4, PTCDMET5, PTCDMET6 removed from PTCDSPAR
. *     V9.12.01    18/11/2009  Mike Laming    CAR 208570
. *                 Add PTCDMET4, PTCDMET5, PTCDMET6 - re-defined over PTCDSPAR
. *     V9.11.01    09/04/2009  Ebon Clements  CAR 188098               
. *                 Add index 2
. *     V9.09.01    16/11/2007  Mike Laming    CAR 154835               
. *                 Add Qld. fields PTCDSURB, PTCDSTTE, PTCDPOST 
. *     V9.08.01    17/05/2007  Mike Laming    CAR 125991               
. *                 Added Singapore Cancer Reg fields, extended record to 900
. *     V9.07.01    23/08/2006  J.Tan                        SRF 116977
. *                 Mods Staging - not used
. *     V9.06.01    07/06/2003  J.Tan                        SRF 96476
. *                 Added fields for Estimated/Unknown and Histological Grade
. *                 Changed Staging from catg 'SG' to 'HI'
. *     V9.02.002   21/03/2003  Tracey Nguyen                SRF 23950
. *                 Changed index PATCRDA1 to "U1-8,51-59,9-16"
. *     V9.02.001   08/07/2002 P.D Created FD 
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
.
PATCRDA1   IFILE    SQL, FIXED=1127, KEY="U1-8,51-59,9-16"    
PATCRDA2   IFILE    SQL, FIXED=1127, KEY="U556-563,1-8,51-59,9-16"    
PATCRDA3   IFILE    SQL, FIXED=1127, KEY="U564-571,572-579,1-8,51-59,9-16" 
PATCRDA4   IFILE    SQL, FIXED=1127, KEY="U590-597,598-605,1-8,51-59,9-16"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
DPTCDDAD  DIM       8      8        1     Patient Admission Number           
DPTCDCNR  DIM       8      8        9     Cancer Registration Number         
PTCDADTE  DIM       8      8        17    Date of 1st Admis (CCYYMMDD)       
PTCDDDTE  DIM       8      8        25    Date of 1st Diag (CCYYMMDD)        
PTCDTMRC  DIM       8      8        33    Date of Tumour Recurrence (CCYYMMDD)
PTCDMTSP  DIM       8      8        41    Date Metastatic Spread (CCYYMMDD)  
PTCDUKPR  FORM      1      2        49    Unknown Primary 0=No 1=Yes         
PTCDPRMM  DIM       9      9        51    Primary Site (Diagnosis) ICD10 Code 
PTCDHTYP  DIM       9      9        60    Histological Type - ICD10 Code     
PTCDMET1  DIM       9      9        69    Metastatic Type 1 - ICD10 Code     
PTCDMET2  DIM       9      9        78    Metastatic Type 2 - ICD10 Code     
PTCDMET3  DIM       9      9        87    Metastatic Type 3 - ICD10 Code     
PTCDLATR  DIM       3      3        96    Laterality (Cat LY)                
PTCDSTAG  DIM       3      3        99    Other Staging Scheme (Cat sS)
.                                         Basis for Diagnosis - This Facility
PTCDBT01  DIM       1      1        102   This Fac. - Clinical Only   0=No 1=Yes
PTCDBT02  DIM       1      1        103   This Fac. - Biochemistry    0=No 1=Yes
PTCDBT03  DIM       1      1        104   This Fac. - Imaging         0=No 1=Yes
PTCDBT04  DIM       1      1        105   This Fac. - Endoscopy       0=No 1=Yes
PTCDBT05  DIM       1      1        106   This Fac. - Explor.Surgery  0=No 1=Yes
PTCDBT06  DIM       1      1        107   This Fac. - Cytology/Haematl 0=No 1=Y
PTCDBT07  DIM       1      1        108   This Fac. - Hist. Of Meta    0=No 1=Y
PTCDBT08  DIM       1      1        109   This Fac. - Hist. Of Primary 0=No 1=Y
PTCDBT09  DIM       1      1        110   This Fac. - Other           0=No 1=Yes
PTCDBT10  DIM       1      1        111   This Fac. - Autopsy         0=No 1=Yes
PTCDOTDG  DIM       50     50       112   Other Diag (this facility) free text
.
PTCDRFLG  FORM      1      2        162   Readmission Flag 0=No 1=Yes        
PTCDPATH  DIM       9      9        164   Pathology Code - ICD10 Code        
PTCDDGPR  DIM       1      1        173   Cancer Diagnosed prior to admission 
.                                         0=No 1=Yes 2=Unknown
PTCDFCPR  DIM       250    250      174   Facility prev diagnosed at.        
.                                         Basis for Diagnosis - Other Facility
.                                         Victoria - Blocks of 80 characters
.                                         lines 1 to 3  of comment
PTCDBO01  DIM       1      1        424   Other Fac.- Clinical Only   0=No 1=Yes
PTCDBO02  DIM       1      1        425   Other Fac.- Biochemistry    0=No 1=Yes
PTCDBO03  DIM       1      1        426   Other Fac.- Imaging         0=No 1=Yes
PTCDBO04  DIM       1      1        427   Other Fac.- Endoscopy       0=No 1=Yes
PTCDBO05  DIM       1      1        428   Other Fac.- Explor.Surgery  0=No 1=Yes
PTCDBO06  DIM       1      1        429   Other Fac.- Cytology/Haematl 0=No 1=Y
PTCDBO07  DIM       1      1        430   Other Fac.- Hist. Of Meta    0=No 1=Y
PTCDBO08  DIM       1      1        431   Other Fac.- Hist. Of Primary 0=No 1=Y
PTCDBO09  DIM       1      1        432   Other Fac.- Other           0=No 1=Yes
PTCDDGOT  DIM       50     50       433   Other Diagnosis (other facility)   
PTCDAUTP  FORM      1      2        483   Cancer Diagnosed on Autopsy only 
.                                                     0=No 1=Yes
PTCDBRLW  FORM      2.3    4        485   Breslow Thickness                  
PTCDMLIN  DIM       3      3        489   Melanoma Invasion Level (Cat IL)   
PTCDRPLB  DIM       3      3        492   Reporting Lab (Cat LB)             
PTCDBTSZ  FORM      2.3    4        495   Breast Tumour Size                 
PTCDCKLV  DIM       3      3        499   Clarks Level                       
PTCDGLSC  FORM      2.3    4        502   Gleason Score                      
PTCDCOMM  DIM       50     50       506   Comments                           
PTCDDTEX  DIM       8      8        556   Date extracted (CCYYMMDD)          
PTCDDTRC  DIM       8      8        564   Date Record Created (CCYYMMDD)     
PTCDTMCR  DIM       8      8        572   Time Record Created (HH:MM:SS)     
PTCDUSCR  DIM       10     10       580   User who created record            
PTCDDTUP  DIM       8      8        590   Date Record Updated (CCYYMMDD)     
PTCDTMUP  DIM       8      8        598   Time Record Updated (HH:MM:SS)     
PTCDUSUP  DIM       10     10       606   User who last updated record       
PTCDBSDG  DIM       3      3        616   Basis of Diagnosis NZ. (Cat BD) 
PTCDESTM  DIM       1      1        619   Estimated Date Flag(Estimated/Unknown)
PTCDCELT  DIM       1      1        620   Histological Grade/Differentation or
.                                         Cell type for leukaemias
.
....                                      Singapore Cancer Registory
PTCDDOCC  DIM       10     10       621   Doctor/Cons.in Charge (dflt.- Att.Doc)
PTCDDOCN  DIM       10     10       631   Notifying Doctor
PTCDNTDT  DIM       8      8        641   Date of Notification (yyyymmdd)
PTCDSNT1  DIM       1      1        649   Source of Notification 1 - SN
PTCDSNT2  DIM       1      1        650   Source of Notification 2 - OR
PTCDSNT3  DIM       1      1        651   Source of Notification 3 - RS
PTCDBOD1  DIM       1      1        652   Basis of Diag. 1 - Death Certif Only
PTCDBOD2  DIM       1      1        653   Basis of Diag. 2 - Clinical only
PTCDBOD3  DIM       1      1        654   Basis of Diag. 3 - Clinical Investig'n
PTCDBOD4  DIM       1      1        655   Basis of Diag. 4 - Specif Tumor Marker
PTCDBOD5  DIM       1      1        656   Basis of Diag. 5 - Cytology
PTCDBOL5  DIM       10     10       657   Basis of Diag. 5 - Cytology Lab No.
PTCDBOD6  DIM       1      1        667   Basis of Diag. 6 - Metastasis
PTCDBOL6  DIM       10     10       668   Basis of Diag. 6 - Metastasis Lab No.
PTCDBOD7  DIM       1      1        678   Basis of Diag. 7 - Primary Tumor
PTCDBOL7  DIM       10     10       679   Basis of Diag. 7 - Prim. Tumor Lab No.
PTCDGD01  DIM       1      1        689   Grade/Differen. 1 Well      1=Y, 0=N
PTCDGD02  DIM       1      1        690   Grade/Differen. 2 Moderate  1=Y, 0=N
PTCDGD03  DIM       1      1        691   Grade/Differen. 3 Poor      1=Y, 0=N
PTCDGD04  DIM       1      1        692   Grade/Differen. 4 Undifferentiated
PTCDGD05  DIM       1      1        693   Grade/Differen. 5 T-Cell    1=Y, 0=N
PTCDGD06  DIM       1      1        694   Grade/Differen. 6 B-Cell    1=Y, 0=N
PTCDGD07  DIM       1      1        695   Grade/Differen. 7 Null Cell 1=Y, 0=N
PTCDGD08  DIM       1      1        696   Grade/Differen. 8 NK Cell   1=Y, 0=N
PTCDGD09  DIM       1      1        697   Grade/Differen. 9 N.O.S.    1=Y, 0=N
PTCDPLOD  DIM       25     25       698   Place of Death
PTCDCOD1  DIM       35     35       723   Cause of Death line 1
PTCDCOD2  DIM       35     35       758   Cause of Death line 2
PTCDCSGT  DIM       10     10       793   Clinical Stage T
PTCDCSGN  DIM       10     10       803   Clinical Stage N
PTCDCSGM  DIM       10     10       813   Clinical Stage M
PTCDCSSG  DIM       10     10       823   Clinical Stage - Stage Grouping
PTCDCSCM  DIM       10     10       833   Classification Manual
PTCDTNON  DIM       1      1        843   Treatment - No Treatment   1=Yes, 0=No
PTCDTSUR  DIM       1      1        844   Treatment - Surgery        1=Yes, 0=No
PTCDTSDT  DIM       8      8        845   Treatment - Surgery  initiation Date
PTCDTRAD  DIM       1      1        853   Treatment - Radiotherapy   1=Yes, 0=No
PTCDTRDT  DIM       8      8        854   Treatment - Radiotherapy  init. Date
PTCDTCHM  DIM       1      1        862   Treatment - Chemotherapy   1=Yes, 0=No
PTCDTCDT  DIM       8      8        863   Treatment - Chemo    initiation Date
PTCDTHOR  DIM       1      1        871   Treatment - Hormones       1=Yes, 0=No
PTCDTHDT  DIM       8      8        872   Treatment - Hormones initiation Date
PTCDTBIO  DIM       1      1        880   Treatment - Biologcal/Other 1=Yes,0=No
PTCDTBDT  DIM       8      8        881   Treatment - Biologcal initiation Date
PTCDRLDT  DIM       8      8        889   Date of First Relapse (yyyymmdd)
PTCDNDCL  DIM       35     35       897   Notifying Dept / Clinic
PTCDTSAB  DIM       1      1        932   Treating Hosp. - This (Same-as-above)
PTCDTOTH  DIM       1      1        933   Treating Hosp. - Other         1=Y 0=N
PTCDTHOS  DIM       35     35       934   Treating Hosp. - Other Hosp.Name
PTCDRST1  DIM       1      1        969   Resident Status - Sing.Citizen 1=Y 0=N
PTCDRST2  DIM       1      1        970   Resident Status - Sing.PR      1=Y 0=N
PTCDRST3  DIM       1      1        971   Resident Status - Malaysia     1=Y 0=N
PTCDRST4  DIM       1      1        972   Resident Status - Indonesia    1=Y 0=N
PTCDRST5  DIM       1      1        973   Resident Status - Other        1=Y 0=N
.
PTCDSURB  DIM       45     45       974   Suburb/Locality of First Diagnosis
PTCDSTTE  DIM       7      7        1019  State of First Diagnosis
PTCDPOST  DIM       8      8        1026  Postcode of First Diagnosis
.                                                                     *C-208570
PTCDMET4  DIM       9      9        1034  Metastatic Type 4 - ICD10 Code
PTCDMET5  DIM       9      9        1043  Metastatic Type 5 - ICD10 Code
PTCDMET6  DIM       9      9        1052  Metastatic Type 6 - ICD10 Code
PTCDECOG  DIM       3      3        1061  ECOG Performance Status (Cat EO)
PTCDRADI  DIM       3      3        1064  Radiotherapy eviQ detail (Cat QF)
PTCDSYST  DIM       3      3        1067  Systemic Agent Therapy eviQ detail
.                                         (Cat QF)
PTCDSCFL  DIM       1      1        1070  Stage of Cancer Flag
.                                          0 or Blank = No
.                                          1 = Yes
PTCDCSSY  DIM       3      3        1071  Cancer Staging System (Cat Cs)
PTCDBDIA  DIM       3      3        1074  Best Basis for Diagnosis (Cat Bd)
PTCDSPAR  DIM       50     50       1077  Spare
.
.End of Record                      1127
.
.Redefine FORM fields from key
.---------------------------------------
PTCDDADN  DIM       8       Patient Admission Number           
PTCDCNRG  FORM      8       Cancer Registration Number         
