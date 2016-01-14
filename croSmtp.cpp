// croSmtp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "smtp/CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

		mail.SetSMTPServer("smtp.zoho.com", 587);
		mail.SetSecurityType(USE_TLS);
		mail.SetCharSet("utf-8");

		mail.SetLogin("olo101");

		char tmpInput[16] = "";
		std::cout << "pass> ";
		std::cin >> tmpInput;
		mail.SetPassword(tmpInput);

		mail.SetSenderName("OLO");
		mail.SetSenderMail("olo101@zoho.com");	// ������ ��� �ּ�
		//mail.SetReplyTo("olo101@zoho.com");	// ȸ�� ���� �ּ�
		mail.SetSubject(L"�ѱ����� ����");			// ����
		mail.AddRecipient("pjm@ebook.co.kr");	// ���� ��� �ּ�
		//mail.SetXPriority(XPRIORITY_NORMAL);
		//mail.SetXMailer("The Bat! (v3.02) Professional");
		mail.AddMsgLine("Hello!");
		mail.AddMsgLine("");
		//mail.AddMsgLine("...");
		mail.AddMsgLine("How are you today?");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");
		//mail.ModMsgLine(5, "regards");
		//mail.DelMsgLine(2);
		//mail.AddMsgLine("User");

		//mail.AddAttachment("c:\\Users\\Kang\\Downloads\\video_sample.mp4");
		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch (ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if (!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}

