package com.man.activity;

import java.util.List;

import com.example.eat.R;
import com.man.adapter.CourseAdapter;
import com.man.dao.CourseDao;
import com.man.entity.Course;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class LearnAcitity extends Activity {
	
	private ListView listView;
	private List<Course> courList;
	private String stuId;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.course_layout);
		
		Intent intent = getIntent();
		stuId = intent.getStringExtra("stu_id");
		//System.out.println("ѧ�ţ� ====== "+stuId);
		
		listView = (ListView) findViewById(R.id.show_course);
		
		CourseDao courseDao = new CourseDao(LearnAcitity.this);
		courList = courseDao.getAll();
		if (courList == null) {
			Log.e("t_course: ", "û����");
			return;
		}
		
		CourseAdapter adapter = new CourseAdapter(LearnAcitity.this, R.layout.course_item_layout, courList);
		listView.setAdapter(adapter);
		
		//ListView
		listView.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				Course course = courList.get(position);//�õ�Ҫ��ʾ�ľ������
				
				Bundle bundle = new Bundle();
				bundle.putString("cour_name", course.getCourName());
				bundle.putString("class_room", course.getClassRoom());
				bundle.putString("class_number", course.getClassNum());
				bundle.putString("teacher", course.getTeacher());
				bundle.putString("stu_id", stuId);
				
				//�������ݰ�����CourInfo��ʾ
				Intent toCourInfo = new Intent(LearnAcitity.this, CourInfo.class);
				toCourInfo.putExtras(bundle);
				
				startActivity(toCourInfo);
				
			}
		});
	}

}
