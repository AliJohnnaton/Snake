#include "Texture.h"

Font font, mfont;
int M = 30, N = 20, heal = 3, mob = 0, d = 2, num = 3, score = 0, v=0, s1=0, q=50, s2=0, kolv=22, vi=0, rul=0;
double pix = 25, piy = 0, wi(0), hi(0), mw(0), mh(0), timer = 0, delay = 0.15, timerm = 0, delaym = 15,mtimer=0,mdelay=0.06, otimer = 0, odelay = 0.06;
Sound Happle, Happ, Fall;
RenderWindow window, woptions, wmenu;
Sprite tile, Snak, Snak1, apple, Heal, GO, Menu;
vector<Sprite> Snakes, Snakes1;
Text score1, Play, Options, Rules, Exit;
vector<Text> SnakeS, SnakeS1;
vector<Texture> SN, SN1;
Clock oclock;

struct Snake
{
 int x, y, z;
}s[600];

struct Nap
{
	int x;
}p[600];

struct Apple
{
	int f3;
	int x, y;
}f, f2, fu[100];

void Game()
{
	for (int i = num; i > 0; --i)
	{
		p[i].x = p[i - 1].x;
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (d == 1)
	{
		p[0].x = 1;
		s[0].x -= 1;
	}
	if (d == 2)
	{
		p[0].x = 2;
		s[0].x += 1;
	}
	if (d == 3)
	{
		p[0].x = 3;
		s[0].y -= 1;
	}
	if (d == 4)
	{
		p[0].x = 4;
		s[0].y += 1;
	}

	for (int i(2); i < num; ++i)
	{
		if (num > 3)
			if (s[0].x == s[i].x && s[0].y == s[i].y)
			{
				
				if (heal == 1)
				{
					Fall.play();
					heal = 0;
					s[0].z = 1;
					timer = 0;
					delay = 15;
				}
				else
				{
					Happ.play();
					int numi = num - i;
					num = num - numi;
					score -= numi * 10;
					heal -= 1;
				}
			}
	}
	if (rul == 0)
	{
		if (s[0].x > M - 1)
			s[0].x = 0;
		if (s[0].x < 0)
			s[0].x = M - 1;
		if (s[0].y > N - 1)
			s[0].y = 0;
		if (s[0].y < 0)
			s[0].y = N - 1;
	}
	else
	{
		if ((s[0].x == M) || (s[0].x == -1))
		{
			s[0].z = 1;
			delay = 15;
		}
		if ((s[0].y == N)||(s[0].y==-1))
		{
			s[0].z = 1;
			delay = 15;
		}
	}

	if ((score % 100 == 0 && score != 0) && f2.f3 != 1)
	{
		f2.x = rand() % M;
		f2.y = rand() % N;
		f2.f3 = 1;
	}
	if (timerm>delaym)
	{
		timerm = 0;
		delay -= 0.01;
		fu[mob].x = rand() % M;
		fu[mob++].y = rand() % N;
		if (mob == 100)
			mob = 0;
	}
	if ((s[0].x == f2.x) && (s[0].y == f2.y))
	{
		Happle.play();
		f2.f3 = 0;
		f2.x = M + 1;
		f2.y = N + 1;
		if (heal == 3)
		{
			num += 3;
			score += 30;
		}
		else
		{
			heal += 1;
		}
	}
	for (int i(0); i < 100; ++i)
	{
		if ((s[0].x == fu[i].x) && (s[0].y == fu[i].y))
		{
			if (heal == 1)
				Fall.play();
			else
			    Happ.play();
			if (mob == 100)
				mob = 0;
			if (num > 3)
				num -= 2;
			score -= 20;
			fu[i].x = M + 1;
			fu[i].y = N + 1;
			heal -= 1;
			
		}
	}


	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		Happle.play();
		bool w = false;
		if(score>=0)
	       num++;
		score += 10;
		for (int i(0); i < num; ++i)
		{
			f.x = rand() % M;
			f.y = rand() % N;
			w = false;
			for (int j(0); j < num; ++j)
			{
				if (f.x == s[j].x && f.y == s[j].y)
					w = true;
			}
			for (int j(0); j < 100; ++j)
			{
				if (f.x == fu[j].x && f.y == fu[j].y)
					w = true;
			}
			if (!w)
				break;
		}
	}

	if (heal == 0)
	{
		s[0].z = 1;
		delay = 15;
	}
}

void zmeyka()
{
	for (int i(0); i < num; ++i)
	{

		int pos = p[i].x;

		if ((i > 0 && i != num - 1) && (p[i - 1].x != p[i].x))
		{
			int a, b;
			a = p[i - 1].x;
			b = p[i].x;
			int c = 0;
			if ((a == 1 && b == 4) || (a == 3 && b == 2))
			{
				c = 0;
			}
			else if ((a == 4 && b == 2) || (a == 1 && b == 3))
			{
				c = 1;
			}
			else if ((a == 2 && b == 3) || (a == 4 && b == 1))
			{
				c = 2;
			}
			else
			{
				c = 3;
			}
			Snak.setTextureRect(IntRect(c * q, 2 * q, q, q));
			Snak1.setTextureRect(IntRect(c * q, 2 * q, q, q));
		}
		else if (i > 0 && i != num - 1)
		{
			Snak.setTextureRect(IntRect((pos - 1) * q, 1 * q, q, q));
			Snak1.setTextureRect(IntRect((pos - 1) * q, 1 * q, q, q));
		}
		else if (i == num - 1)
		{
			int a;
			a = p[i - 1].x;
			Snak.setTextureRect(IntRect((a - 1) * q, 3 * q, q, q));
			Snak1.setTextureRect(IntRect((a - 1) * q, 3 * q, q, q));
		}
		else
		{
			if (s[0].z == 1) {
				Snak.setTextureRect(IntRect((pos - 1) * q, 4 * q, q, q));
				Snak1.setTextureRect(IntRect((pos - 1) * q, 4 * q, q, q));
			}
			else {
				Snak.setTextureRect(IntRect((pos - 1) * q, 0 * q, q, q));
				Snak1.setTextureRect(IntRect((pos - 1) * q, 0 * q, q, q));
			}
		}
		Snak.setScale(pix / q, piy / q);
		Snak.setPosition(s[i].x * pix, s[i].y * piy);
		window.draw(Snak);
		Snak1.setScale(pix / q, piy / q);
		Snak1.setPosition(s[i].x * pix, s[i].y * piy);
		window.draw(Snak1);
	}
	apple.setTextureRect(IntRect(0, 0, 32, 32));
	apple.setScale(pix / 32, piy / 32);
	apple.setPosition(f.x * pix, f.y * piy);
	window.draw(apple);

	apple.setTextureRect(IntRect(32, 0, 32, 32));
	apple.setScale(pix / 32, piy / 32);
	apple.setPosition(f2.x * pix, f2.y * piy);
	window.draw(apple);

	apple.setTextureRect(IntRect(64, 0, 32, 32));
	for (int i(0); i < 100; ++i)
	{
		apple.setScale(pix / 25, piy / 25);
		apple.setPosition(fu[i].x * pix, fu[i].y * piy);
		window.draw(apple);
	}
	Heal.setTextureRect(IntRect(heal * 29, 0, 29, 16));
	Heal.setScale(pix / 25, piy / 25);
	Heal.setPosition(0 * pix, 0 * piy);
	window.draw(Heal);

}

void wGame()
{
	window.create(VideoMode::getDesktopMode(), "Snake", Style::Fullscreen);
	window.setMouseCursorVisible(false);

	
	

	Clock clock;
	clock.restart();

	Clock clockm;
	clockm.restart();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		float timem = clockm.getElapsedTime().asSeconds();
		clockm.restart();
		timerm += timem;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A)))
		{
			if (d == 2)
				d = 2;
			else
				d = 1;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D)))
		{
			if (d == 1)
				d = 1;
			else
				d = 2;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)))
		{
			if (d == 4)
				d = 4;
			else
				d = 3;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S)))
		{
			if (d == 3)
				d = 3;
			else
				d = 4;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		//������ ��������
		if ((timer > delay) && (s[0].z != 1))
		{
			timer = 0;
			Game();
		}

		window.clear();

		//��������� ����
		for (int i(0); i < M; ++i)
			for (int j(0); j < N; ++j)
			{
				tile.setPosition(i * pix, j * piy);
				window.draw(tile);
			}
		//��������� ������ � ��������
		zmeyka();

		//��������� ���������
		if (s[0].z == 1)
		{
			window.draw(GO);
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				delay = 0.15;
				num = 3;
				s[0].z = 0;
				s[0].x = 0;
				s[0].y = 0;
				d = 2;
				score = 0;
				heal = 3;
				for (int i(0); i < 100; ++i)
				{
					fu[i].x = M + 1;
					fu[i].y = N + 1;
				}
			}
			if (timer > delay && s[0].z == 1)
			{
				delay = 0.15;
				num = 3;
				s[0].z = 0;
				s[0].x = 0;
				s[0].y = 0;
				d = 2;
				score = 0;
				heal = 3;
				for (int i(0); i < 100; ++i)
				{
					fu[i].x = M + 1;
					fu[i].y = N + 1;
				}
				window.close();
			}

		}
		//����� �����
		char temp[256];
		sprintf_s(temp, "Score: %i", score);
		score1.setString(temp);
		window.draw(score1);

		window.display();
	}
}

void wOptions()
{
	Sprite Sn0, Sn01;
	woptions.create(VideoMode::getDesktopMode(), "Options", Style::Fullscreen);
	woptions.setMouseCursorVisible(false);
	
	oclock.restart();
	int pol = 38;
	for (int i(0); i < kolv; ++i)
	{
		int polx = 10;
		SnakeS[i].setFont(mfont);
		SnakeS[i].setCharacterSize(20);
		SnakeS[i].setFillColor(Color::White);
		SnakeS[i].setPosition(polx, pol);
		Vector2<float> score_scale(1.5f, 1.5f);
		SnakeS[i].setScale(score_scale);
		SnakeS[i].setString(to_string(i + 1));
		polx = 60;
		SnakeS1[i].setFont(mfont);
		SnakeS1[i].setCharacterSize(20);
		SnakeS1[i].setFillColor(Color::White);
		SnakeS1[i].setPosition(polx, pol);
		SnakeS1[i].setScale(score_scale);
		SnakeS1[i].setString(to_string(i + 1));
		pol += 45;
	}

	while (woptions.isOpen())
	{
		float otime = oclock.getElapsedTime().asSeconds();
		oclock.restart();
		otimer += otime;
		Event evento;
		while (woptions.pollEvent(evento))
		{
			if (evento.type == Event::Closed)
				woptions.close();
		}
		
		for (int i(0); i < SnakeS.size(); ++i)
		{
			SnakeS[i].setFillColor(Color::White);
			SnakeS1[i].setFillColor(Color::White);
		}
		
		
		
		if (otimer > odelay)
		{
			otimer = 0;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				woptions.close();
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (vi==0)
					vi=1;
				else
					vi=0;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (vi == 1)
					vi = 0;
				else
					vi = 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				switch (vi)
				{
				case 0:
					if (s1 == 21)
						s1 = 0;
					else
						s1 += 1;
					break;
				case 1:
					if (s2 == 21)
						s2 = 0;
					else
						s2 += 1;
					break;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				switch (vi)
				{
				case 0:
					if (s1 == 0)
						s1 = 21;
					else
						s1 -= 1;
					break;
				case 1:
					if (s2 == 0)
						s2 = 21;
					else
						s2 -= 1;
					break;
				}
			}
			SnakeS[s1].setFillColor(Color::Red);
			SnakeS1[s2].setFillColor(Color::Red);

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				Snak = Snakes[s1];
				Snak1 = Snakes1[s2];
				v = 0;
				woptions.close();
			}

			Sn0 = Snakes[s1];
			Sn01 = Snakes1[s2];
			woptions.draw(Menu);
			for (int i(0); i < kolv; ++i)
			{
				woptions.draw(SnakeS[i]);
				woptions.draw(SnakeS1[i]);
			}
			int xp(400), pp(0);
			for (int i(0); i < 3; ++i)
			{
				if (i == 2)
					pp = 3;
				Sn0.setTextureRect(IntRect(0*q, pp*q, q, q));
				Sn0.setScale(8, 8);
				Sn0.setPosition(xp, 300);
				woptions.draw(Sn0);
				Sn01.setTextureRect(IntRect(0 * q, pp * q, q, q));
				Sn01.setScale(8, 8);
				Sn01.setPosition(xp, 300);
				woptions.draw(Sn01);
				xp += 400;
				pp += 1;
			}



			woptions.display();
		}
		
	}
}

void WMenu()
{
	vector<Text> PMenu{ Play,Options,Rules,Exit };
	vector<String> SMenu{ "Play","Options","<Mode>","Exit" };
	int pol = 250;
	vector<double> pok{ wi / 2 - 70 * mw, wi / 2 - 135 * mw,wi / 2 - 140 * mw,wi / 2 - 65 * mw };
	for (int i(0); i < PMenu.size(); ++i)
	{
		PMenu[i].setFont(mfont);
		PMenu[i].setCharacterSize(50);
		PMenu[i].setFillColor(Color::White);
		PMenu[i].setPosition(pok[i], pol*mh);
		Vector2<float> score_scale(1.5f, 1.5f);
		PMenu[i].setScale(score_scale);
		PMenu[i].setString(SMenu[i]);
		pol += 150;
	}
	Text gmode;
	gmode.setFont(mfont);
	gmode.setCharacterSize(50);
	gmode.setFillColor(Color::Cyan);
	gmode.setPosition(wi/2+500*mw, 10);
	Vector2<float> score_scale(1.5f, 1.5f);
	gmode.setScale(score_scale);
	gmode.setString("Classic");

	wmenu.create(VideoMode::getDesktopMode(), "Menu", Style::Fullscreen);
	wmenu.setMouseCursorVisible(false);

	Clock mclock;
	mclock.restart();

	while (wmenu.isOpen())
	{
		float mtime = mclock.getElapsedTime().asSeconds();
		mclock.restart();
		mtimer += mtime;

		Event eventm;
		while (wmenu.pollEvent(eventm))
		{
			if (eventm.type == Event::Closed)
				wmenu.close();
		}

		for (int i(0); i < PMenu.size(); ++i)
			PMenu[i].setFillColor(Color::White);
		if (mtimer > mdelay)
		{
			mtimer = 0;
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (v == 3)
					v = 0;
				else
					v += 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (v == 0)
					v = 3;
				else
					v -= 1;
			}
			PMenu[v].setFillColor(Color::Red);
			if (v == 2)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					if (rul == 0)
						rul = 1;
					else
						rul = 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					if (rul == 1)
						rul = 0;
					else
						rul = 1;
				}
			}

			if(rul==0)
				gmode.setString("Classic");
			else
				gmode.setString("Room");


			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				switch (v)
				{
				case 0:
				{
					wGame();
					break;
				}
				case 1:
				{
					wOptions();
					break;
				}
				case 3:
				{
					wmenu.close();
				}
				}
			}

			wmenu.draw(Menu);
			for (int i(0); i < 4; ++i)
			{
				wmenu.draw(PMenu[i]);
			}
			wmenu.draw(gmode);
			wmenu.display();
		}
	}
}

int main()
{
	Snakes.resize(kolv);
	SnakeS.resize(kolv);
	SnakeS1.resize(kolv);
	Snakes1.resize(kolv);
	SN.resize(kolv);
	SN1.resize(kolv);
	setlocale(LC_ALL, "ru");
	srand(time(0));

	//����������� ���������� ������
	wi = VideoMode::getDesktopMode().width;
	hi = VideoMode::getDesktopMode().height;
	pix = wi / M;
	piy = hi / N;
	mw = wi/1760;
	mh = hi/990;

	f.x = rand() % M;
	f.y = rand() % N;

	f2.x = M + 1;
	f2.y = N + 1;
	for (int i(0); i < 100; ++i)
	{
		fu[i].x = M + 1;
		fu[i].y = N + 1;
	}

	SoundBuffer happle;
	happle.loadFromFile("Snake/apple.wav");
	Happle.setBuffer(happle);

	SoundBuffer happ;
	happ.loadFromFile("Snake/happ.wav");
	Happ.setBuffer(happ);

	SoundBuffer fall;
	fall.loadFromFile("Snake/fall.wav");
	Fall.setBuffer(fall);

	//�������� �������

	Texture menu;
	menu.loadFromFile("Menu/Menu.jpg");
	Menu.setTexture(menu);
	Menu.setScale(mw, mh);
	Menu.setPosition(0, 0);

	for (int i(0); i < Snakes.size(); ++i){
		SN[i].loadFromFile("Snake/Tex/SN" + to_string(i) + ".png");
		Snakes[i].setTexture(SN[i]);
		SN1[i].loadFromFile("Snake/Tex2/SN" + to_string(i) + ".png");
		Snakes1[i].setTexture(SN1[i]);}
	Snak = Snakes[s1];
	Snak1 = Snakes1[s2];

	Texture tex;
	tex.loadFromFile("Snake/ground.png");
	tile.setTexture(tex);
	tile.setScale(pix / 25, piy / 25);

	Texture go;
	go.loadFromFile("Snake/gameover.png");
	GO.setTexture(go);
	GO.setScale(pix / 25, piy / 25);
	GO.setPosition(5 * pix, 4 * piy);

	Texture ap;
	ap.loadFromFile("Snake/apple.png");
	apple.setTexture(ap);

	Texture h0;
	h0.loadFromFile("Snake/Heal.png");
	Heal.setTexture(h0);
	
	//������� �������� �����
	
	font.loadFromFile("light-arial.ttf");
	score1.setFont(font);
	score1.setCharacterSize(30);
	score1.setFillColor(Color(255, 0, 255, 255));
	score1.setPosition(10, hi - 50);
	Vector2<float> score_scale(1.5f, 1.5f);
	score1.setScale(score_scale);
	score1.setString("Score: 0");

	mfont.loadFromFile("Menu/Menu.ttf");
	
	WMenu();
}