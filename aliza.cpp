#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
/*
    create an attribute in ttt class name pieces
    pieces -> array of sprite
    
    sprite-> texture(0,8)
    --loop--
    even = circle
    odd = cross
    sprite[0] = circle
    sprite[0].setPosition()
    sprite[1] = cross 
    sprite[1].setPostiion() 




    //main function
    use for loop in main to print sprite in window


*/

class TicTacToe{
    public:
    sf::Image boardImage;
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
    
    sf::Image circleImage;
    sf::Texture circleTexture;
    sf::Sprite circleSprite;

    sf::Image crossImage;
    sf::Texture crossTexture;
    sf::Sprite crossSprite;
     
    sf::Image blankImage;
    sf::Texture blankTexture;
    sf::Sprite blankSprite;

    sf::Sprite pieces[9];
    sf::Text player1;
    sf::Text player2;
    sf::Font font;
   

    int count;
    int check[9] ;
    // sf::Sprite crossSprite;
    // sf::Sprite circleSprite;

    public:
    TicTacToe(){
        for(int i=0;i<9;i++){
        this->check[i]=0;
        }
        this->count = 0;
         if(!font.loadFromFile("Resources/font.ttf"))
    {
// error...
}
        player1.setString("Player 1");
        player1.setFont(font);
        player1.setCharacterSize(24);
        player1.setFillColor(sf::Color::Red);
        player2.setString("Player 2");
        player2.setFont(font);
        player2.setCharacterSize(24);
        player2.setFillColor(sf::Color::Red);
    }
    void loadImages(){
        
        //loading board sprite
        
        if(!this->boardImage.loadFromFile("Resources/board.png"))
        {
            cout<<"image not loaded"<<endl;  
        }
        this->boardTexture.loadFromImage(this->boardImage);
        this->boardSprite.setTexture(this->boardTexture);

        //loading circle sprite
        if(!this->circleImage.loadFromFile("Resources/circle.png"))
        {
            cout<<"image not loaded"<<endl;  
        }
        this->circleTexture.loadFromImage(this->circleImage);
        this->circleSprite.setTexture(this->circleTexture);

        //loading cross sprite
         if(!this->crossImage.loadFromFile("Resources/cross.png"))
        {
            cout<<"image not loaded"<<endl;  
        }
        this->crossTexture.loadFromImage(this->crossImage);
        this->crossSprite.setTexture(this->crossTexture);

        if(!this->blankImage.loadFromFile("Resources/blank.png"))
        {
            cout<<"image not loaded"<<endl;  
        }
        this->blankTexture.loadFromImage(this->blankImage);
        this->blankSprite.setTexture(this->blankTexture);
    }
    
    void loadPieces(){
        int position[9][9]={{0,0},{140,0},{280,0},{0,140},{140,140},{280,140},{0,280},{140,280},{280,280}};
        //use for loop to do other operation
        for(int i = 0;i<9;i++){
           // if(i%2==0){
                pieces[i]=blankSprite;
                pieces[i].setPosition(position[i][0],position[i][1]);
            //}
            // else{
            //     pieces[i]=crossSprite;
            //     pieces[i].setPosition(position[i][0],position[i][1]);
            // }
        }
    }

    void click(sf::Vector2i mouse_position){
        int position[9][9]={{0,0},{140,0},{280,0},{0,140},{140,140},{280,140},{0,280},{140,280},{280,280}};
        if(count%2==0){
            for(int i =0;i<9;i++){
                
                if(check[i]==0 && pieces[i].getGlobalBounds().contains(mouse_position.x,mouse_position.y)){
                pieces[i] = circleSprite;
                pieces[i].setPosition(position[i][0],position[i][1]);
                check[i] = 1;
                this->count++;
                   


                }
            }
        }
        else{
           for(int i =0;i<9;i++){
                if(check[i]==0 && pieces[i].getGlobalBounds().contains(mouse_position.x,mouse_position.y)){
                pieces[i] = crossSprite;
                pieces[i].setPosition(position[i][0],position[i][1]);
                check[i] = 2;
                this->count++;
                }
            }
        }
    }

    void set_playername(){
       


        
    }

    bool gameover(){

            if(check[0]==check[1] && check[1] == check[2] && check[0]!=0){
                return true;
            }
            
            if(check[3]==check[4] && check[4] == check[5] && check[3]!=0){
                return true;
            }

            if(check[6]==check[7] && check[7] == check[8] && check[6]!=0){
               return true;
            }
            
            if(check[0]==check[3] && check[3] == check[6] && check[0]!=0){
                return true;
            }

            if(check[1]==check[4] && check[4] == check[7] && check[1]!=0){
                return true;
            }

            if(check[2]==check[5] && check[5] == check[8] && check[2]!=0){
                return true;
            }

            if(check[0]==check[4] && check[4] == check[8] && check[0]!=0){
                return true;
            }

            if(check[2]==check[4] && check[4] == check[6] && check[2]!=0){
                return true;
            }

                return false;
            

    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400),"Tic tac toe");
    TicTacToe t;
    t.loadImages();
    t.loadPieces();
    t.set_playername();
    while (window.isOpen()) 
    {
        sf::Event event;
        window.clear();
        window.draw(t.boardSprite);
        for(int i =0;i<9;i++){
        window.draw(t.pieces[i]); 
       }

        window.display();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);  
                // cout<<mouse_position.x<<endl;
                // cout<<mouse_position.y<<endl;
            t.click(mouse_position);
            if(t.gameover()){
                cout<<"game over"<<endl;
                for(int i =0;i<9;i++){
                t.pieces[i]= t.blankSprite;
                }   
             }
            
            

            cout<<t.count<<endl;
            for(int i =0;i<9;i++){
             window.draw(t.pieces[i]); 
            }
            if(t.count%2==0){
                window.draw(t.player1);
            }

            else{
                window.draw(t.player2);
            }
            
            window.display();
            }   
            
        }       
}
     return 0;
}
