PlatformToolSet=v143:VCToolArchitecture=Native32Bit:VCToolsVersion=14.32.31326:TargetPlatformVersion=10.0.22000.0:
Debug|Win32|F:\PROGRAMIRANJE\C++\TEST\_ThinkLAP\|
                                                                                                                                                                                                                                                                                                                                                         ulaRjesenje();

	// slova
	// -      -> promijeni mod
	// ' '    -> razmak
	// 
	//		   R, -,   i,   g,  h,    t,   -, ?  ' '  -  Y  - e    s   -  !
	// input: 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
	//pog2.decodeMessage();
	//pog2.decodeMessageRjesenje();

	// vjezbe
	//pog2.vj1();
	//pog2.vj2();
	//pog2.vj2_version2();
	//pog2.vj3();
	//// input: 9780306406157 (978-0-306-40615-7)
	//pog2.vj5_check();
	//// input: 978030640615 (978-0-306-40615-?)
	//pog2.vj5_generate();
	try
	{
		//std::cout << pog2.vj6_bin_to_dec() << '\n';
		//int bin = pog2.vj6_dec_to_bin();
		//pog2.vj6_ispisi_bin(bin);
		////std::cout << bin;
		struct testCase {			// b									d				h
			int test1 = 0;			// 0									0				0x0
			int test2 = 5;			// 101									5				0x5
			int test3 = -5;			// 11111111111111111111111111111011		-5				0xFFFC
			int test4 = INT32_MIN;	// 10000000000000000000000000000000		-2147483648		0x8000
		};
		//pog2.vj7_pretvorba_sa_hex();
		////--------------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>(neg brojevi)pog2.vj8_pretvorba_sve_baze();
	}
	catch (const char* poruka)
	{
		std::cout << poruka;
	}
	catch(...)
	{
		std::cout << "--GRESKA!--\n";
	}
	//test cases:
	// rE, 
	// Ree, 
	// aaaaaa Uhhhhh,
	//    bbboKKK   ,
	
	//std::string str;
	//std::cout << "Unesi liniju teksta:\n";
	//getline(std::cin, str);
	//pog2.vj9_unos_string_info(str);


	Poglavlje3 pog3;
	//pog3.finding_the_mode();

	//pog3.vj1_sorting();
	////pog3.highestSales_zadano();
	//pog3.vj2_median();
	//std::array<int, 20> niz1{ 5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534, 23, 55, 67, 99, 265, 376, 232, 223 };
	//std::array<int, 20> niz2{ 23, 55, 67, 99, 223, 232, 265, 376, 1122, 2534, 3838, 3875, 3983, 4785, 4959, 5456, 5865, 6464,  7766, 9957 };
	//std::cout << ((pog3.vj3_issorted(niz1) == true) ? "sortiran\n" : "nije sortiran\n");
	//std::cout << ((pog3.vj3_issorted(niz2) == true) ? "sortiran\n" : "nije sortiran\n");

	try
	{
		// cipher:	┼ ( ? I ž 0 _ ) = E 5 ! ╣ < ' ╦ $ » ╩ 8 U ▀ ď Ó ─ ╝
		// slova:	a b c d e f g h i j k l m n o p q r s t u v w x y z
		const char* plainText = "roses are red, balls are blue. life suck and so are you.";
		auto encoded = pog3.vj4_cipher_encode(plainText);
		std::cout.setf(std::ios::left); std::cout.width(12); std::cout << "plainText:" << plainText << '\n';
		std::cout.setf(std::ios::left); std::cout.width(12); std::cout << "encoded:" << encoded << '\n';
		std::cout << '\n';

		char cipherText[57];
		strcpy_s(cipherText, encoded.get());
		auto decode = pog3.vj5_cipher_decode(std::move(encoded));
		std::cout.setf(std::ios::left); std::cout.width(12); std::cout << "cipherText:" << cipherText << '\n';
		std::cout.setf(std::ios::left); std::cout.width(12); std::cout << "decode:" << decode << '\n';
	}
	catch (const char* str)
	{
		std::cout << str;
	}
	catch (...)
	{
		std::cout << "--GRESKA--\n";
	}



	return 0;
}