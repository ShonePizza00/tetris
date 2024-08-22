#pragma once
#ifndef CHARS_HPP
#define CHAR_HPP
#include <vector>

namespace charshpp
{
	const std::vector<char> offsetChars = {
		0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};
	const std::vector<char> widthShapes = {
		3, 3, 2, 3, 4, 3, 3
	};
	const std::vector<std::vector<std::vector<bool>>> chars = {
			{
				{0,1,1,1,0},
				{1,0,0,0,0},
				{0,1,1,0,0},
				{0,0,0,1,0},
				{1,1,1,0,0}
			},
			{
				{0,1,1,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{0,1,1,0,0}
			},
			{
				{0,1,1,0,0},
				{1,0,0,1,0},
				{1,0,0,1,0},
				{1,0,0,1,0},
				{0,1,1,0,0}
			},
			{
				{1,0,1,1,0},
				{1,1,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0}
			},
			{
				{0,1,1,0,0},
				{1,0,0,1,0},
				{1,1,1,1,0},
				{1,0,0,0,0},
				{0,1,1,1,0}
			},
			{
				{0,1,0,0,0},
				{1,0,1,0,0},
				{1,0,1,0,0},
				{1,0,1,0,0},
				{0,1,0,0,0}
			},
			{
				{0,1,0,0,0},
				{1,1,0,0,0},
				{0,1,0,0,0},
				{0,1,0,0,0},
				{1,1,1,0,0}
			},
			{
				{1,1,1,0,0},
				{0,0,1,0,0},
				{0,1,0,0,0},
				{1,0,0,0,0},
				{1,1,1,0,0}
			},
			{
				{1,1,1,0,0},
				{0,0,1,0,0},
				{0,1,0,0,0},
				{0,0,1,0,0},
				{1,1,1,0,0}
			},
			{
				{1,0,1,0,0},
				{1,0,1,0,0},
				{1,1,1,0,0},
				{0,0,1,0,0},
				{0,0,1,0,0}
			},
			{
				{1,1,1,0,0},
				{1,0,0,0,0},
				{1,1,0,0,0},
				{0,0,1,0,0},
				{1,1,0,0,0}
			},
			{
				{0,1,1,0,0},
				{1,0,0,0,0},
				{1,1,0,0,0},
				{1,0,1,0,0},
				{0,1,0,0,0}
			},
			{
				{1,1,1,0,0},
				{0,0,1,0,0},
				{0,1,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,0}
			},
			{
				{0,1,0,0,0},
				{1,0,1,0,0},
				{0,1,0,0,0},
				{1,0,1,0,0},
				{0,1,0,0,0}
			},
			{
				{0,1,0,0,0},
				{1,0,1,0,0},
				{0,1,1,0,0},
				{0,0,1,0,0},
				{1,1,0,0,0}
			}
	};
	const std::vector<std::vector<std::vector<bool>>> shapes = {
		{
			{1,1,0,0},
			{0,1,1,0}
		},
		{
			{0,0,1,0},
			{1,1,1,0}
		},
		{
			{1,1,0,0},
			{1,1,0,0}
		},
		{
			{0,1,1,0},
			{1,1,0,0}
		},
		{
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{1,1,1,0}
		},
		{
			{1,0,0,0},
			{1,1,1,0}
		}
	};
}

#endif // !CHARS_HPP
