#include "Core.hpp"
#include "Torrent.hpp"

#include <cstdlib>

extern "C" 
{
#include "gtorrent-core.h"

// gtorrent core functions

gt_core* core_create()
{
	return reinterpret_cast<gt_core*>(new gt::Core());
}

bool is_magnet_link(gt_core *g, char *link)
{
	const string url(link);
	return reinterpret_cast<gt::Core*>(g)->isMagnetLink(url);
}

const char* get_default_save_path(gt_core *g)
{
	return reinterpret_cast<gt::Core*>(g)->getDefaultSavePath().c_str();
}

gt_torrent** get_torrents(gt_core *g)
{
	vector<shared_ptr<Torrent>> vec = reinterpret_cast<gt::Core*>(g)->getTorrents();

	gt_torrent **array = (gt_torrent**)malloc(sizeof(gt_torrent*)*vec.size());

	for (unsigned int i = 0; i < vec.size(); ++i)
		array[i] = reinterpret_cast<gt_torrent*>(vec[i].get());

	return array;
}

gt_torrent* add_torrent(gt_core *g, char *path)
{
	string str(path);
	Torrent *torrent = reinterpret_cast<gt::Core*>(g)->addTorrent(str).get();
	return reinterpret_cast<gt_torrent*>(torrent);
}

bool is_running(gt_core *g)
{
	return reinterpret_cast<gt::Core*>(g)->isRunning();
}

void core_shutdown(gt_core *g)
{
	reinterpret_cast<gt::Core*>(g)->shutdown();
}

void update(gt_core *g)
{
	reinterpret_cast<gt::Core*>(g)->update();
}

int32_t get_number_torrents(gt_core *g)
{
	vector<shared_ptr<Torrent>> vec = reinterpret_cast<gt::Core*>(g)->getTorrents();
	return vec.size();
}

// gtorrent torrent functions

bool poll_event(gt_torrent *t, gt_event *e)
{
	gt::Event *event = reinterpret_cast<gt::Event*>(e);
	return reinterpret_cast<Torrent*>(t)->pollEvent(*event);
}

bool is_paused(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->isPaused();
}

int64_t get_active_time(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getActiveTime();
}

int get_state(gt_torrent *t)
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

float get_total_progress(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalProgress();
}

uint32_t get_upload_rate(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getUploadRate();
}

uint32_t get_download_rate(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getDownloadRate();
}

uint32_t get_ppm_progress(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getPPMProgress();
}

uint32_t get_total_seeders(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalSeeders();
}

uint32_t get_total_peers(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalPeers();
}

uint32_t get_total_leechers(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalLeechers();
}

int64_t get_total_uploaded(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalUploaded();
}

int64_t get_total_downloaded(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalDownloaded();
}

int64_t get_size(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getSize();
}

int64_t get_wanted(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getWanted();
}

int64_t get_torrent_size(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTorrentSize();
}

int64_t get_time_remaining(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTimeRemaining();
}

float get_total_ratio(gt_torrent *t)
{
	return reinterpret_cast<Torrent*>(t)->getTotalRatio();
}

char* get_path(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getPath().c_str());
}

char* get_current_tracker_url(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getCurrentTrackerURL().c_str());
}

char* get_text_active_time(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextActiveTime().c_str());
}

char* get_text_state(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextState().c_str());
}

char* get_text_upload_rate(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextUploadRate().c_str());
}

char* get_text_download_rate(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextDownloadRate().c_str());
}

char* get_text_total_uploaded(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalUploaded().c_str());
}

char* get_text_total_downloaded(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalDownloaded().c_str());
}

char* get_text_size(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextSize().c_str());
}

char* get_text_remaining(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextRemaining().c_str());
}

char* get_text_total_ratio(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTotalRatio().c_str());
}

char* get_text_time_remaining(gt_torrent *t)
{
	return const_cast<char*>(reinterpret_cast<Torrent*>(t)->getTextTimeRemaining().c_str());
}

void set_save_path(gt_torrent *t, char *path)
{
	string savepath(path);
	reinterpret_cast<Torrent*>(t)->setSavePath(savepath);
}

//void force_recheck(gt_torrent *t)
//{
//	reinterpret_cast<Torrent*>(t)->torrentForceRecheck();
//}

void set_paused(gt_torrent *t, bool paused)
{
	reinterpret_cast<Torrent*>(t)->setPaused(paused);
}

void t_resume(gt_torrent *t)
{
	reinterpret_cast<Torrent*>(t)->resume();
}

void t_pause(gt_torrent *t)
{
	reinterpret_cast<Torrent*>(t)->pause();
}

} // extern "C"
