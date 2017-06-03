#include <SDL2/SDL.h>

typedef struct SDL_Rect_Q : SDL_Rect {
	int p, xi, yi, l, d;
	double v;
	bool canMove = true;
	SDL_Rect_Q(int x_inicial, int y_inicial, int lado, double velocidade, int tam_desloc){
		p = 0;
		xi = x = x_inicial; 
		yi = y = y_inicial; 
		w = h = l = lado;
		d = tam_desloc;
		v = velocidade;
	}

} SDL_Rect_Q;

void verifyClickRet(SDL_MouseButtonEvent* c, SDL_Rect_Q* r){
	if ((c->x > r->x) && (c->x <= r->x + r->l) && (c->y > r->y) && (c->y <= r->y + r->l)) {
		r->canMove = false;		
	}	
}

void moveRet(SDL_Rect_Q* r, unsigned long long dt){
	int tmp;

	if (r->v < 0){
		tmp = (int) (r->p + dt * r->v + 400)%400;
	}else{
		tmp = (int) (r->p + dt * r->v) % 400;
	}

	if ( tmp <= r->d){
		r->x = r->xi + tmp;
		r->y = r->yi;
	} else 

	if (tmp <= 2 * r->d){
		r->x = r->xi + r->d;
		r->y = r->yi + (tmp - r->d);
	} else

	if (tmp <= 3 * r->d){
		r->x = r->xi + r->d - (tmp - 2*r->d);
		r->y = r->yi + r->d;

	} else{
		r->x = r->xi;
		r->y = r->yi + r->d - (tmp - 3*r->d);
	}

	r->p = tmp;
	
}

void drawRet(SDL_Rect_Q* r, unsigned long long dt, SDL_Renderer* renderer, int c1, int c2, int c3, int c4){
	SDL_SetRenderDrawColor(renderer, c1,c2,c3,c4);
	SDL_RenderFillRect(renderer, r);
}


int main (int argc, char* args[]){

    /* INITIALIZATION */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Hello World!",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            640, 480, SDL_WINDOW_SHOWN
                         );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	unsigned long long tempoAnterior = SDL_GetTicks(), dt = 0;
    SDL_Event e;
	SDL_Rect_Q r1 = { 10, 10, 50, 0.5, 100};
    SDL_Rect_Q r2 = { 200 , 200, 100, -0.5, 100};

    /* EXECUTION */
    while (1) {
		SDL_PollEvent(&e);    
		dt = SDL_GetTicks() - tempoAnterior;
		tempoAnterior = SDL_GetTicks();

		if (e.type == SDL_QUIT) {
			break;
		} else if (e.type == SDL_MOUSEBUTTONDOWN) {
			SDL_MouseButtonEvent* c = (SDL_MouseButtonEvent*) &e;
			verifyClickRet(c, &r1);
			verifyClickRet(c, &r2);
		}

		if (r1.canMove) moveRet(&r1, dt);
		if (r2.canMove) moveRet(&r2, dt);

        SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderFillRect(renderer, NULL);

		drawRet(&r1,dt,renderer,0x00,0x00,0xFF,0x00);
		drawRet(&r2,dt,renderer,0x00,0xFF,0xFF,0x00);

        SDL_RenderPresent(renderer);
    }

    /* FINALIZATION */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
