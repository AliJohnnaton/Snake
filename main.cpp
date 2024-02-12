#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;

Text score1, Play, Options, Rules, Exit;
Font font, mfont;
int M = 30, N = 20, heal = 3, mob = 0, d = 2, num = 3, score = 0, v=0, s1=5;
double pix = 25, piy = 0, wi(0), hi(0), timer = 0, delay = 0.15, timerm = 0, delaym = 15,mtimer=0,mdelay=0.05, otimer = 0, odelay = 0.05;
Sprite tile, Snak, apple, Heal, GO, WRules, Menu;
Sound Happle, Happ, Fall;
RenderWindow window, woptions, wmenu, wrules;
Sprite Sn1, Sn2, Sn3, Sn4, Sn5, Sn6, Sn7, Sn8, Sn9, Sn10, Sn11, Sn12, Sn13, Sn14, Sn15, Sn16, Sn17, Sn18, Sn19, Sn20, Sn21, Sn22,Sn23;
vector<Sprite> Snakes{ Sn1, Sn2, Sn3, Sn4, Sn5, Sn6, Sn7, Sn8, Sn9, Sn10, Sn11, Sn12, Sn13, Sn14, Sn15, Sn16, Sn17, Sn18, Sn19, Sn20, Sn21, Sn22,Sn23 };
Text SN1, SN2, SN3, SN4, SN5, SN6, SN7, SN8, SN9, SN10, SN11, SN12, SN13, SN14, SN15, SN16, SN17, SN18, SN19, SN20, SN21, SN22,SN24;
vector<Text> SnakeS{ SN1, SN2, SN3, SN4, SN5, SN6, SN7, SN8, SN9, SN10, SN11, SN12, SN13, SN14, SN15, SN16, SN17, SN18, SN19, SN20, SN21, SN22,SN24 };
Texture sn1, sn2, sn3, sn4, sn5, sn6, sn7, sn8, sn9, sn10, sn11, sn12, sn13, sn14, sn15, sn16, sn17, sn18, sn19, sn20, sn21, sn22, sn23;
vector<Texture> SN23{ sn1, sn2, sn3, sn4, sn5, sn6, sn7, sn8, sn9, sn10, sn11, sn12, sn13, sn14, sn15, sn16, sn17, sn18, sn19, sn20, sn21, sn22, sn23 };

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

	if (s[0].x > M - 1)
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = M - 1;
	if (s[0].y > N - 1)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = N - 1;

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
			Snak.setTextureRect(IntRect(c * 25, 2 * 25, 25, 25));

		}
		else if (i > 0 && i != num - 1)
		{
			Snak.setTextureRect(IntRect((pos - 1) * 25, 1 * 25, 25, 25));
		}
		else if (i == num - 1)
		{
			int a;
			a = p[i - 1].x;
			Snak.setTextureRect(IntRect((a - 1) * 25, 3 * 25, 25, 25));
		}
		else
		{
			if (s[0].z == 1)
				Snak.setTextureRect(IntRect((pos - 1) * 25, 4 * 25, 25, 25));
			else
				Snak.setTextureRect(IntRect((pos - 1) * 25, 0 * 25, 25, 25));
		}
		Snak.setScale(pix / 25, piy / 25);
		Snak.setPosition(s[i].x * pix, s[i].y * piy);
		window.draw(Snak);
	}
	apple.setTextureRect(IntRect(0, 0, 32, 32));
	apple.setScale(pix / 25, piy / 25);
	apple.setPosition(f.x * pix, f.y * piy);
	window.draw(apple);

	apple.setTextureRect(IntRect(32, 0, 32, 32));
	apple.setScale(pix / 25, piy / 25);
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

	f.x = rand() % M;
	f.y = rand() % N;

	f2.x = M + 1;
	f2.y = N + 1;
	for (int i(0); i < 100; ++i)
	{
		fu[i].x = M + 1;
		fu[i].y = N + 1;
	}

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

		//Запуск механики
		if ((timer > delay) && (s[0].z != 1))
		{
			timer = 0;
			Game();
		}

		window.clear();

		//Отрисовка поля
		for (int i(0); i < M; ++i)
			for (int j(0); j < N; ++j)
			{
				tile.setPosition(i * pix, j * piy);
				window.draw(tile);
			}
		//отрисовка змейки и объектов
		zmeyka();

		//Отрисовка ГеймОвера
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
		//Вывод очков
		char temp[256];
		sprintf_s(temp, "Score: %i", score);
		score1.setString(temp);
		window.draw(score1);

		window.display();
	}
}

void wOptions()
{
	Sprite Sn0;
	woptions.create(VideoMode::getDesktopMode(), "Options", Style::Fullscreen);
	woptions.setMouseCursorVisible(false);
	Clock oclock;
	oclock.restart();
	int pol = 38;
	for (int i(0); i < SnakeS.size(); ++i)
	{
		SnakeS[i].setFont(mfont);
		SnakeS[i].setCharacterSize(20);
		SnakeS[i].setFillColor(Color::White);
		SnakeS[i].setPosition(10, pol);
		Vector2<float> score_scale(1.5f, 1.5f);
		SnakeS[i].setScale(score_scale);
		SnakeS[i].setString(to_string(i+1));
		pol += 38;
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
			SnakeS[i].setFillColor(Color::White);
		

		
		if (otimer > odelay)
		{
			otimer = 0;
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				woptions.close();
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (s1 == 22)
					s1 = 22;
				else
					s1 += 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (s1 == 0)
					s1 = 0;
				else
					s1 -= 1;
			}
			SnakeS[s1].setFillColor(Color::Red);

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				Snak = Snakes[s1];
				woptions.close();
			}

			Sn0 = Snakes[s1];
			woptions.draw(Menu);
			for (int i(0); i < Snakes.size(); ++i)
				woptions.draw(SnakeS[i]);
			int xp(400), pp(0);
			for (int i(0); i < 3; ++i)
			{
				if (i == 2)
					pp = 3;
				Sn0.setTextureRect(IntRect(0*25, pp*25, 25, 25));
				Sn0.setScale(16, 16);
				Sn0.setPosition(xp, 300);
				woptions.draw(Sn0);
				xp += 400;
				pp += 1;
			}



			woptions.display();
		}
		
	}
}

void wRules()
{
	wrules.create(VideoMode::getDesktopMode(), "Rules", Style::Fullscreen);
	wrules.setMouseCursorVisible(false);

	while (wrules.isOpen())
	{
		Event eventr;
		while (wrules.pollEvent(eventr))
		{
			if (eventr.type == Event::Closed)
				wrules.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			wrules.close();

		wrules.draw(WRules);
		wrules.display();
	}
}

void WMenu()
{
	vector<Text> PMenu{ Play,Options,Rules,Exit };
	vector<String> SMenu{ "Play","Options","Rules","Exit" };
	int pol = 250;
	vector<double> pok{ wi / 2 - 70, wi / 2 - 135,wi / 2 - 100,wi / 2 - 60 };
	for (int i(0); i < PMenu.size(); ++i)
	{
		PMenu[i].setFont(mfont);
		PMenu[i].setCharacterSize(50);
		PMenu[i].setFillColor(Color::White);
		PMenu[i].setPosition(pok[i], pol);
		Vector2<float> score_scale(1.5f, 1.5f);
		PMenu[i].setScale(score_scale);
		PMenu[i].setString(SMenu[i]);
		pol += 150;
	}

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
				case 2:
				{
					wRules();
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
			wmenu.display();
		}
	}
}

int main()
{
	
	setlocale(LC_ALL, "ru");
	srand(time(0));

	//Определение разрешения экрана
	wi = VideoMode::getDesktopMode().width;
	hi = VideoMode::getDesktopMode().height;
	pix = wi / M;
	piy = hi / N;

	SoundBuffer happle;
	happle.loadFromFile("Snake/apple.wav");
	Happle.setBuffer(happle);

	SoundBuffer happ;
	happ.loadFromFile("Snake/happ.wav");
	Happ.setBuffer(happ);

	SoundBuffer fall;
	fall.loadFromFile("Snake/fall.wav");
	Fall.setBuffer(fall);

	//Загрузка текстур

	Texture menu;
	menu.loadFromFile("Menu/Menu.jpg");
	Menu.setTexture(menu);
	Menu.setPosition(0, 0);

	Texture Wrules;
	Wrules.loadFromFile("Menu/Rules.jpg");
	WRules.setTexture(Wrules);
	WRules.setPosition(0, 0);

	for (int i(0); i < Snakes.size(); ++i)
	{

		SN23[i].loadFromFile("Snake/Tex/SN" + to_string(i) + ".png");
		Snakes[i].setTexture(SN23[i]);
		
	}
	Snak = Snakes[s1];

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
	
	//Задание настроек Очков
	
	font.loadFromFile("Minecraft Rus NEW.otf");
	score1.setFont(font);
	score1.setCharacterSize(20);
	score1.setFillColor(Color(255, 0, 150, 100));
	score1.setPosition(10, hi - 50);
	Vector2<float> score_scale(1.5f, 1.5f);
	score1.setScale(score_scale);
	score1.setString("Score: 0");

	mfont.loadFromFile("Menu/Menu.ttf");
	
	WMenu();

}