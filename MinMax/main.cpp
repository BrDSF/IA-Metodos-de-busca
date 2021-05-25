#include <iostream>

class Tabuleiro
{
private:
  char tabuleiro[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
  Player player;

public:
  void exibeTabuleiro()
  {
    std::cout << "    0"
              << "   1 "
              << "  2   " << std::endl;
    std::cout << "+-------------+" << std::endl;

    for (int i = 0; i < 3; i++)
    {
      std::cout << i;
      std::cout << " | ";
      for (int j = 0; j < 3; j++)
      {
        std::cout << tabuleiro[i][j] << " | ";
      }
      std::cout << std::endl;
    }
    std::cout << "+-------------+";
  }
  bool empate()
  {
    for (int i = 0; i < 3; i++)
    {
      if (tabuleiro[i][0] == player.getNenhum() || tabuleiro[i][1] == player.getNenhum() || tabuleiro[i][2] == player.getNenhum())
        return false;
    }
    return true;
  }
  bool vitoria(Player player)
  {
    for (int i = 0; i < 3; i++)
    {
      if ((tabuleiro[i][0] == player.getJogador1() || tabuleiro[i][0] == player.getJogador2()) && (tabuleiro[i][1] == player.getJogador1() || tabuleiro[i][1] == player.getJogador2()) && (tabuleiro[i][2] == player.getJogador1() || tabuleiro[i][2] == player.getJogador2()))
        return true;
      if ((tabuleiro[0][i] == player.getJogador1() || tabuleiro[0][i] == player.getJogador2()) && (tabuleiro[1][i] == player.getJogador1() || tabuleiro[1][i] == player.getJogador2()) && (tabuleiro[2][i] == player.getJogador1() || tabuleiro[2][i] == player.getJogador2()))
        return true;
    }
    return false;
  }
};
class Player
{
private:
  char nenhum = '-';
  char jogador1 = 'X';
  char jogador2 = 'O';

public:
  char getNenhum()
  {
    return nenhum;
  }
  char getJogador1()
  {
    return jogador1;
  }
  char getJogador2()
  {
    return jogador2;
  }
};
class Jogar
{
};

int main()
{
  Tabuleiro tabuleiro;
  tabuleiro.exibeTabuleiro();
  return 0;
}