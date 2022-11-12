#include <chrono>
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

#include <opencv2/ximgproc.hpp>
#include <opencv2/imgcodecs.hpp>

namespace fs = std::filesystem;


std::vector<std::string> GetFilesFromDirectory(const std::string& dir)
{
	std::vector<std::string> results;

	namespace fs = std::filesystem;
	fs::path someDir;
	if (dir.empty())
	{
		someDir = fs::path(fs::current_path());
	}
	else
	{
		someDir = fs::path(dir);
	}

	fs::directory_iterator end_iter;

	if (fs::exists(someDir) && fs::is_directory(someDir))
	{
		for (fs::directory_iterator dir_iter(someDir); dir_iter != end_iter; ++dir_iter)
		{
			if (fs::is_regular_file(dir_iter->status()))
			{
				// result_set.insert(result_set_t::value_type(fs::last_write_time(dir_iter->path()), *dir_iter));
				results.push_back((*dir_iter).path().string());
			}
		}
	}

	return results;
}



int main()
{
    auto files = GetFilesFromDirectory("../gabor");


	// Read images
	std::vector<cv::Mat> images;
	images.reserve(files.size());

	for (const auto& f : files)
	{
		// Opening files
		std::cout << "Opening file: " << f << "\n";

		auto first = cv::imread(f, CV_8UC1);

		if (first.empty() == false)
		{
			images.emplace_back(first);
		}
		else
		{
			std::cerr << "Could not open file " << f<< "\n";
		}
	}


	struct timing_data
	{
		cv::Mat thinned_image;
		std::chrono::milliseconds duration;
	};

	std::vector<timing_data> thinned;
	thinned.reserve(files.size());

	// Performing thinning
	for (const auto &p : images)
	{
		cv::Mat out;

		auto start = std::chrono::high_resolution_clock::now();

		std::cout << "Thinning on " << p.size() << "... ";
		cv::ximgproc::thinning(p, out, 1);

		auto dur = std::chrono::high_resolution_clock::now() - start;

		thinned.emplace_back(out, std::chrono::duration_cast<std::chrono::milliseconds>(dur));

		std::cout << "Used " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << "ms\n";
	}


    return 0;
}

