<%
if Request("generatereport") = "true" then
	Response.Buffer = TRUE ' For IIS 4 compatibility
	set rr = Server.CreateObject("RRATL.RSWControl")
	rr.reportName = "You must enter a valid report file name.RSW"
	rr.runReport
else
%>

<HTML><HEAD>
<TITLE>Report Viewer Control Document</TITLE>
</HEAD><BODY>

<object WIDTH="85%" HEIGHT="85%" 
		CLASSID="CLSID:66960E23-DE25-11CF-876F-444553540000" 
		 codebase="rrprview.cab#Version=2,0,0,4" id=RepView1>
		<param NAME="LanguageID" VALUE="0409">
		<param NAME="ReportURL" VALUE="<%= Request.ServerVariables("SCRIPT_NAME") %>?generatereport=true">
		
		<embed WIDTH="95%" HEIGHT="95%" 
		CLASSID="CLSID:66960E23-DE25-11CF-876F-444553540000" 
		CODEBASE="rrprview.cab#Version=2,0,0,4" 
		TYPE="application/oleobject" 
		PARAM_ReportURL=""></object>
</BODY>
</HTML>

<%
end if
%>

