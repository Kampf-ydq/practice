package com.man.activity;

import com.example.eat.R;
import com.man.dao.UserDao;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EditInfo extends Activity {
	
	private EditText nick;
	private EditText school;
	private Button save;
	private String acc;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.edit_infor);
		
		Intent intent = getIntent();
		acc = intent.getStringExtra("stu_id");
		
		nick = (EditText) findViewById(R.id.edit_nick);
		school = (EditText) findViewById(R.id.edit_school);
		save = (Button) findViewById(R.id.save_edit_info);
		
		save.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				String NICK = nick.getText().toString().trim();
				String SCHOOL = school.getText().toString().trim();
				
				if (TextUtils.isEmpty(NICK) || TextUtils.isEmpty(SCHOOL)) {
					Toast.makeText(EditInfo.this, "��������ȷ����Ϣ", 0).show();
					return;
				}
				
				//���¼�¼
				UserDao userDao = new UserDao(EditInfo.this);
				userDao.updateInfo(SCHOOL, NICK, acc);
				
				//��������
				Intent toPerActivity = new Intent();
				toPerActivity.putExtra("nick", NICK);
				toPerActivity.putExtra("school", SCHOOL);
				setResult(RESULT_OK, toPerActivity);
				Toast.makeText(EditInfo.this, "�޸ĳɹ�", 0).show();
				finish();
			}
		});
	}

   
}
