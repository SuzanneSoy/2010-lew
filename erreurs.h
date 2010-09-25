#define die(msg) {\
	fprintf(stderr, msg "\n"); \
	fprintf(stderr, "  %s\n", SDL_GetError()); \
	exit(EXIT_FAILURE); \
}

