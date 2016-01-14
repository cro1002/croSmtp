// croSmtp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
		//mail.SetCharSet("utf-8"); // 기본값을 utf-8로 설정

		mail.SetLogin("olo101");

		char tmpInput[16] = "";
		std::cout << "pass> ";
		std::cin >> tmpInput;
		mail.SetPassword(tmpInput);

		mail.SetSenderName(L"나는나");
		mail.SetSenderMail("olo101@zoho.com");		// 보내는 사람 주소
		mail.SetReplyTo("cro1002@naver.com");		// 회신 받을 주소
		mail.SetSubject(L"smtp한글 메일보내기");		// 제목
		mail.AddRecipient("pjm@ebook.co.kr", L"바로YOU");	// 받을 사람 주소
		mail.AddCCRecipient("cro1002@gmail.com", L"또다른나");
		//mail.SetXPriority(XPRIORITY_NORMAL);
		//mail.SetXMailer("The Bat! (v3.02) Professional");
		mail.AddMsgLine(L"안녕하세요!");
		mail.AddMsgLine(L"");
		mail.AddMsgLine(L"반갑습니다 abcd hello~!お久しぶりです。！");
		mail.AddMsgLine(L"");
		mail.AddMsgLine(L"안녕히 Goodbye~!　さよなら★");
		mail.AddAttachment(L"c:\\Users\\Kang\\Desktop\\박정민\\nextest\\관상동맥우회수술\\222.png");
		mail.AddAttachment(L"c:\\Users\\Kang\\Desktop\\박정민\\CS문서\\Designer.hwp");
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

