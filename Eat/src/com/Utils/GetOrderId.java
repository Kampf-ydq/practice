package com.Utils;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class GetOrderId {

	public static String produceOrderId(){
		//��ʽ����ǰʱ��
		SimpleDateFormat sfDate = new SimpleDateFormat("yyyyMMddHHmmssSSS");
		String strDate = sfDate.format(new Date());
		//�õ�17λʱ���磺20170411094039080
		System.out.println("ʱ��17λ��" + strDate);
		//Ϊ�˷�ֹ�߲����ظ�,�ٻ�ȡ3�������
		String random = getRandom620(3);
		
		//���õ�20λ������š�
		String orderId = strDate + random;
		System.out.println("������20λ��" + strDate + random);
		return orderId;
	}
	
	/**
	 * ��ȡ6-10 �����λ������
	 * @param length	��Ҫ���ɵĳ���
	 * @return result
	 */
	public static String getRandom620(Integer length) {
		String result = "";
		Random rand = new Random();
		int n = 20;
		if (null != length && length > 0) {
			n = length;
		}
		int randInt = 0;
		for (int i = 0; i < n; i++) {
			randInt = rand.nextInt(10);
			result += randInt;
		}
		return result;
	}
	
}
