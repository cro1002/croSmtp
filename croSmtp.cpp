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
		//mail.SetCharSet("utf-8"); // �⺻���� utf-8�� ����

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
		mail.AddMsgLine(L"�ȳ��ϼ���!");
		mail.AddMsgLine(L"");
		mail.AddMsgLine(L"������ ��Ű���?");
		mail.AddMsgLine(L"");
		mail.AddMsgLine(L"�ȳ���");

		mail.AddAttachment("c:\\Users\\Kang\\Downloads\\video_sample.html");
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

