#include <iostream>
#include <string>

#define QUESTION "Input your request: move, resize, display, close."

class Screen{
    int width = 80;
    int height = 50;
public:
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }

};
class Window{
    Screen screen;
    int top = 10;
    int left = 10;
    int width = 10;
    int height = 10;
public:
    void display(){
        for(int i = 0; i < screen.getHeight(); i++){
            for(int j = 0; j < screen.getWidth(); j++){
                if((i>=top)&&(i<(top+height))&&(j>=left)&&(j<(left+width))){
                    std::cout<<'1';
                }else{
                    std::cout<<'0';
                }
            }
            std::cout<<std::endl;
        }
    }
    void resize(){
        int nW;
        int nH;
        std::cout << "Input new width"<< std::endl;
        std::cin >> nW;
        std::cout << "Input new height"<< std::endl;
        std::cin >> nH;
        setSize(nW,nH);

    };
    void move(){
        int addTop;
        int addLeft;
        std::cout << "Input move vector 'addLeft' 'addTop'" << std::endl;
        std::cin>>addLeft>>addTop;


        if((top + addTop) <= 0) {
            top = 0;
        } else if(top + addTop + height < screen.getHeight()){
            top+=addTop;
        } else {
            top = screen.getHeight() - height;
        }

        if((left + addLeft) <= 0){
            left = 0;
        } else if(left + addLeft + width < screen.getWidth()){
            left+=addLeft;
        } else {
            left = screen.getWidth()-width;
        }
    }

private:
    void setSize(int newWidth, int newHeight){
        if(newWidth <= 0) newWidth = 1;
        if(newHeight <= 0) newHeight = 1;
        if(left+newWidth < screen.getWidth()){
            width = newWidth;
        } else {
            if(newWidth < screen.getWidth()){
                left = screen.getWidth() - newWidth;
                width = newWidth;
            } else {
                left = 0;
                width = screen.getWidth();
            }

        }

        if(top+newHeight < screen.getHeight()){
            height = newHeight;
        } else {
            if(newHeight < screen.getHeight()){
                top = screen.getHeight() - newHeight;
                height = newHeight;
            } else {
                top = 0;
                width = screen.getHeight();
            }
        }
    }



};

int main() {
    auto* window = new Window;
    std::string request;

    std::cout << QUESTION << std::endl;
    std::cin >> request;
    while (request!="close"){
        if(request == "move"){
            window->move();
        } else if(request == "resize"){
            window->resize();
        } else if(request == "display"){
            window->display();
        }
        std::cout << QUESTION << std::endl;
        std::cin >> request;
    }
    delete window;



    return 0;
}
