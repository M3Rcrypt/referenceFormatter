# referenceFormatter
This C program converts the MLA references in a txt file to APA references and saves them into a txt file.

There can be maximum of six authors. 

* If there are six authors, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}, {Surname2}, {Name2}, {Surname3}, {Name3}, {Surname4}, {Name4}, {Surname5}, {Name5}, and {Surname6}, {Name6}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}.<br /> <br />
e.g. Demirel Topel, Seda, Demir, Emre, Öztürk, Yusuf, Börekçi, Selim, Bilge, Alper, and Seyman, Alper. "The importance of electric field distribution for effective in vivo electroporation of tissues." Biophysical 22 (2022): 441-456. <br /> <br />
* If there are five authors, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}, {Surname2}, {Name2}, {Surname3}, {Name3}, {Surname4}, {Name4}, and {Surname5}, {Name5}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}. <br /> <br />
e.g. Aslan, Göksel, Yüksek, Kemal Adem, Kazan, Hilal, Turan, Gözde, and Dipova, Nihat. "How to imlement computer graphics and distributed database systems to civil engineering applications." ResearchGate 234 (2016): 101-151. <br /> <br />
* If there are four authors, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}, {Surname2}, {Name2}, {Surname3}, {Name3}, and {Surname4}, {Name4}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}. <br /> <br />
e.g. Temel, Dursun, Ulaş, Mehmet, Yıldız, Tilbe, and Ijeloula, Esther. "AI and Game Playing Trees." IEEE 234 (1997): 24-28. <br /> <br />
* If there are three authors, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}, {Surname2}, {Name2}, and {Surname3}, {Name3}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}. <br /> <br />
e.g. Yüksek, İsmail, Çalışkan, Cafer, and Erten, Cesim. "Implementing advanced algorithms to find the efficiency of RSA algorithm." Distopia 12 (2011): 21-45. <br /> <br />
* If there are two authors, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}, and {Surname2}, {Name2}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}. <br /> <br />
e.g. Taheri, Shahram, and Önsen, Toygar. "On the use of DAG-CNN architecture for age estimation with multi-stage features fusion." Neurocomputing 329 (2019): 300-310. <br /> <br />
* If there is one author, the format of MLA is as follows: <br /> <br />
{Surname1}, {Name1}. "{ArticleTitle}." {JournalName} {IssueNumber} ({YearOfPublication}): {PageFrom}-{PageTo}. <br /> <br />
e.g. Tur, Mustafa Kürşat Yavuz. "Designing CNN model to predict bank credit analysis." IEEE 99 (2023): 271-281. <br /> <br />


After transforming the references to APA format the format will be as follows (for six authors):
{Surname1}, {The first letter of Name1}., {Surname2}, {The first letter of Name2}., {Surname3}, {The first letter of Name3}., {Surname4}, {The first letter of Name4}., {Surname5}, {The first letter of Name5}., & {Surname6}, {The first letter of Name6}. ({YearOfPublication}). {ArticleTitle}. {JournalName}, {IssueNumber}, {PageFrom}-{PageTo}. 
e.g. Demirel Topel, S., Demir, E., Öztürk, Y., Börekçi, S., Bilge, A., & Seyman, A. (2022). The importance of electric field distribution for effective in vivo electroporation of tissues. Biophysical, 22, 441-456.
and so on.
