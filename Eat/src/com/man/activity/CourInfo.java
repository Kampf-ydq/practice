package com.man.activity;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import com.example.eat.R;
import com.man.adapter.GoodsAdapter;
import com.man.dao.CourseDao;
import com.man.dao.GoodsDao;
import com.man.dao.UserDao;
import com.man.entity.Course;
import com.man.entity.User;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

public class CourInfo extends Activity {
	
	private double UNIT_SM = 0.05;
	
	private TextView courName;
	private TextView classRoom;
	private TextView classNumber;
	private TextView teacher;
	private Button startLearnBtn;
	private Button endLearnBtn;
	private String stuId;
	private double money;
	
	//学习时长
	private String from;
	private String to;
	
	SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.cour_info_model);
		
		//初始化控件
		courName = (TextView) findViewById(R.id.cour_name);
		classRoom = (TextView) findViewById(R.id.class_room);
		classNumber = (TextView) findViewById(R.id.class_number);
		teacher = (TextView) findViewById(R.id.teacher);
		startLearnBtn = (Button) findViewById(R.id.start_learn);
		endLearnBtn = (Button) findViewById(R.id.end_learn);
		
		//获取bundle数据包
		Bundle bundle = getIntent().getExtras();
		stuId = bundle.getString("stu_id");
		
		UserDao userDao = new UserDao(this);
		money = userDao.find(stuId).getMoney();
		
		//System.out.println(stuId);
		//显示数据
		courName.setText(bundle.getString("cour_name"));
		classRoom.setText(bundle.getString("class_room"));
		classNumber.setText(bundle.getString("class_number"));
		teacher.setText(bundle.getString("teacher"));
		
		
		//计算学习时间，给出学习币奖励
		startLearnBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				startDialog();
				
				//记录开始时间
		        from = df.format(new Date());// new Date()为获取当前系统时间
		        System.out.println("开始时间===="+from);
			}
		});
		
		endLearnBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				
				//记录结束时间
		        to = df.format(new Date());// new Date()为获取当前系统时间
		        System.out.println("结束时间===="+to);
		        
		        endDialog();   
		        
		        //更新t_user表中的money值
		        UserDao userDao = new UserDao(CourInfo.this);
		        userDao.updateMoney(money+calSM(), stuId);
		        /*Handler handler = new Handler();
				handler.sendEmptyMessageDelayed(0, 2000);
		        finish();*/
			}
		});

	}
	
	private void startDialog(){
		AlertDialog.Builder builder = new AlertDialog.Builder(CourInfo.this);
		builder.setIcon(R.drawable.startlearn);
		builder.setTitle("温馨提示");
		builder.setMessage("学习结束记得点击结束按钮哦");
		builder.setPositiveButton("我知道了", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				
			}
		});
		AlertDialog dialog = builder.create();
		dialog.show();
	}
	
	private void endDialog(){
		double m = calSM();
		AlertDialog.Builder builder = new AlertDialog.Builder(CourInfo.this);
		builder.setIcon(R.drawable.startlearn);
		builder.setTitle("钱管家");
		builder.setMessage("Dear，这次赚了"+String.valueOf(m)+"学习币");
		builder.setPositiveButton("要了", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				
			}
		});
		AlertDialog dialog = builder.create();
		dialog.show();
	}
	
	//计算学习币
	private double calSM(){
		long start;
		long end;
		double minutes;
		try {
			start = df.parse(from).getTime();
			end = df.parse(to).getTime();
			
			minutes = (double) ((end - start)/(1000 * 60));
			System.out.println("学习时间====="+minutes);
			return minutes * UNIT_SM;
			
		} catch (ParseException e) {
			System.out.println("日期转换有误");
			e.printStackTrace();
		}
		
		return -1;
	}

}
