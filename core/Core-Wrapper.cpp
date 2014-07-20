#include "Core.hpp"
#include "Torrent.hpp"

#include <cstdlib>

extern "C" 
{
#include "gtorrent-core.h"

// gtorrent core functions

gtorrent_core* core_create()
{
	return reinterpret_cast<gtorrent_core*>(new gt::Core());
}

bool is_magnet_link(gtorrent_core *g, char *link)
{
	const string url(link);
	return reinterpret_cast<gt::Core*>(g)->isMagnetLink(url);
}

const char* get_default_save_path(gtorrent_core *g)
{
	return reinterpret_cast<gt::Core*>(g)->getDefaultSavePath().c_str();
}

gtorrent_torrent** get_torrents(gtorrent_core *g)
{
	vector<shared_ptr<Torrent>> vec = reinterpret_cast<gt::Core*>(g)->getTorrents();

	gtorrent_torrent **array = (gtorrent_torrent**)malloc(sizeof(gtorrent_torrent*)*vec.size());

	for (unsigned int i = 0; i < vec.size(); ++i)
		array[i] = reinterpret_cast<gtorrent_torrent*>(vec[i].get());

	return array;
}

gtorrent_torrent* add_torrent(gtorrent_core *g, char *path)
{
	string str(path);
	Torrent *torrent = reinterpret_cast<gt::Core*>(g)->addTorrent(str).get();
	return reinterpret_cast<gtorrent_torrent*>(torrent);
}

bool is_running(gtorrent_core *g)
{
	return reinterpret_cast<gt::Core*>(g)->isRunning();
}

void core_shutdown(gtorrent_core *g)
{
	reinterpret_cast<gt::Core*>(g)->shutdown();
}

void update(gtorrent_core *g)
{
	reinterpret_cast<gt::Core*>(g)->update();
}

int32_t get_number_torrents(gtorrent_core *g)
{
	vector<shared_ptr<Torrent>> vec = reinterpret_cast<gt::Core*>(g)->getTorrents();
	return vec.size();
}

// gtorrent torrent functions

bool poll_event(gtorrent_torrent *t, gtorrent_event *e)
{
	gt::Event *event = reinterpret_cast<gt::Event*>(e);
	return reinterpret_cast<Torrent*>(t)->pollEvent(*event);
}

bool is_paused(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->isPaused();
}

int64_t get_age(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getAge();
}

int get_state(gtorrent_torrent *t)
{
	switch (reinterpret_cast<Torrent*>(t)->getState()) {
	case libtorrent::torrent_status::checking_files:
		return TORRENT_STATE_CHECKING_FILES;
	case libtorrent::torrent_status::seeding:
		return TORRENT_STATE_SEEDING;
	default:
		return TORRENT_STATE_DOWNLOADING;
	}
}

float get_total_progress(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalProgress();
}

uint32_t get_upload_rate(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getUploadRate();
}

uint32_t get_download_rate(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getDownloadRate();
}

uint32_t get_ppm_progress(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getPPMProgress();
}

uint32_t get_total_seeders(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalSeeders();
}

uint32_t get_total_peers(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalPeers();
}

uint32_t get_total_leechers(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalLeechers();
}

int64_t get_total_uploaded(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalUploaded();
}

int64_t get_total_downloaded(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalDownloaded();
}

int64_t get_size(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getSize();
}

int64_t get_wanted(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getWanted();
}

int64_t get_torrent_size(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTorrentSize();
}

int64_t get_time_remaining(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTimeRemaining();
}

float get_total_ratio(gtorrent_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalRatio();
}

char* get_path(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getPath().c_str());
}

char* get_current_tracker_url(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getCurrentTrackerURL().c_str());
}

char* get_text_age(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextAge().c_str());
}

char* get_text_state(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextState().c_str());
}

char* get_text_upload_rate(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextUploadRate().c_str());
}

char* get_text_download_rate(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextDownloadRate().c_str());
}

char* get_text_total_uploaded(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalUploaded().c_str());
}

char* get_text_total_downloaded(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalDownloaded().c_str());
}

char* get_text_size(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextSize().c_str());
}

char* get_text_remaining(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextRemaining().c_str());
}

char* get_text_total_ratio(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalRatio().c_str());
}

char* get_text_time_remaining(gtorrent_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTimeRemaining().c_str());
}

void set_save_path(gtorrent_torrent *t, char *path)
{
	string savepath(path);
	reinterpret_cast<Torrent*>(t)->setSavePath(savepath);
}

void force_recheck(gtorrent_torrent *t)
{
	reinterpret_cast<Torrent*>(t)->torrentForceRecheck();
}

void set_paused(gtorrent_torrent *t, bool paused)
{
	reinterpret_cast<Torrent*>(t)->setPaused(paused);
}

void t_resume(gtorrent_torrent *t)
{
	reinterpret_cast<Torrent*>(t)->resume();
}

void t_pause(gtorrent_torrent *t)
{
	reinterpret_cast<Torrent*>(t)->pause();
}

} // extern "C"
