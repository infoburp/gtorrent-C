#include <stdio.h>
#include <stdlib.h>
#include "core/gtorrent-core.h"

#ifdef WIN32
#include <windows.h>
#define sleep(t) Sleep(t*1000)
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("USAGE: %s path_to_torrent", argv[0]);
			return 1;
	}

	gt_core *g = core_create();
	printf("Core created! Current location is: %p\n", g);

	gt_torrent *t = add_torrent(g, argv[1]);

	if (!t) {
		printf("Invalid Torrent!\n");
		return 1;
	}

	printf("Downloading %s...\n", get_path(t));
	while (1) {
		printf("%s DOWN:%d UP:%d SEEDS:%d PEERS:%d [%d/%d]\n",
				get_text_state(t),
				get_download_rate(t),
				get_upload_rate(t),
				get_total_seeders(t),
				get_total_peers(t),
				get_size(t),
				get_total_progress(t)
				);
		sleep(1);
	}
}
